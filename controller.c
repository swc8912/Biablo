#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/fs.h>
#include <linux/list.h>
#include <linux/errno.h>
#include <asm/uaccess.h>
#include <linux/fcntl.h>
#include <linux/types.h>
#include <linux/wait.h>

#include "vdev_if.h"

#define IPC_IOCTL_NUM 100
#define IPC_OPEN	_IOWR(IPC_IOCTL_NUM,1,unsigned long*)
#define IPC_CLOSE	_IOWR(IPC_IOCTL_NUM,2,unsigned long*)
#define IPC_SEND	_IOWR(IPC_IOCTL_NUM,3,unsigned long*)
#define IPC_RECV	_IOWR(IPC_IOCTL_NUM,4,unsigned long*)
#define IPC_LIST	_IOWR(IPC_IOCTL_NUM,5,unsigned long*)

#define BIABLO_DEV_NAME "/dev/biablo"
#define BIABLO_DEV_MAJOR 201

struct packet
{
    unsigned char src;
    unsigned char dst;
    unsigned char optype:2;
    unsigned char operation:6;
    unsigned char operand[2];
};

struct home_register
{
    unsigned char tx;
    unsigned char src;
    unsigned char dst;
    unsigned char optypeop;
    unsigned char operand[2];
    unsigned char blank;
    unsigned char rx;
    unsigned char src2;
    unsigned char dst2;
    unsigned char optypeop2;
    unsigned char operand2[2];
};

struct home_dev // 현재 연결된 디바이스 구조체
{
    unsigned char addr; // 디바이스 번호
    unsigned char devicetype; // 디바이스 타입: 가전제품 종류
    unsigned char operation[3][2]; // 1 2 3번 타입의 값들을 2바이트로 저장
};

struct packet home_packet; // 패킷 날릴 것
//struct home_register home_regi;
struct home_dev dev_list[254]; // 총 254개 디바이스 연결가능

//void reg_handler(unsigned long); // tasklet 용 핸들러 쓰임새가 없다..
void vdev_reg_handler(int,void*); // vdev에 연결된 핸들러 이걸로 레지스터값을 받아옴

vir_handler fp=vdev_reg_handler;
byte *region; // vdev와 공유하는 포인터 여기로 레지스터 값 참조가능
static int live_dev=0; // 연결된 가전제품 갯수 새는 것
static int flag=0; //  브로드캐스팅 2번이상 할때 체크용 live_dev 0으로

void init_devlist()
{
    int i,j;

    for(i=0; i<254; i++)
    {
        dev_list[i].addr=255;
        dev_list[i].devicetype=255;
        for(j=0; j<3; j++)
        {
            dev_list[i].operation[j][0]=0;
            dev_list[i].operation[j][1]=0;
        }
    }
    printk("init_devlist()\n");
}

int list_pass(unsigned long arg) // dev_list 응용으로 보내기 dev_list[254] 옴
{
    struct home_dev temp[254];

    //	temp=(struct home_dev*)arg;

    //	memcpy(arg,temp,sizeof(dev_list));
    copy_to_user((struct home_dev*)arg,dev_list,sizeof(temp));
    return sizeof(temp);
}

int send_packet(unsigned long arg) // 디바이스에서 가상으로
{
    struct packet temp;
    int i=0;

    unsigned char optypeop;

    //temp=(struct packet*)arg;
    copy_from_user(&temp,(struct packet*)arg,sizeof(temp));

    optypeop=temp.optype;
    printk("temp->optype optypeop=%d\n",optypeop);
    optypeop=optypeop<<6;
    printk("<<6  optypeop=%d\n",optypeop);
    optypeop+=temp.operation;
    printk("in send_packet optypeop=%d\n",optypeop);

    region[1]=temp.src;
    region[2]=temp.dst;
    region[3]=optypeop;
    region[4]=temp.operand[0];
    region[5]=temp.operand[1];

    for(i=0; i<6; i++)
        printk("send_packet: region[%d]=%d\n",i,region[i]);

    if(region[1]==0 && region[2]==255)  // 브로드캐스팅시에 플래그
    {
        printk("in broadcasting flag=%d\n",flag);
        if(flag==0) // 한번 했다고 표시
        {
            flag=1;
            printk("flag=1 ok\n");
        }
        else if(flag==1) // 두번째 이상일 경우
        {
            init_devlist(); // 디바이스 리스트 초기화
            live_dev=0; // 카운트 0만들고 새로
            printk("devlist cleaned\n");
        }
    }
    printk("flag=%d\n",flag);
    region[0]=1; // send 요청 tx=1

    for(i=0; i<6; i++)
        printk("send_packet: region[%d]=%d\n",i,region[i]);

    printk("send_packet 날림\n");

    return sizeof(temp);
}

int recv_packet(unsigned long arg) // 디바이스에서 GUI로 패킷 만들어서 카피투유저
{
    struct packet *packet;
    unsigned char operation=0;

    packet=(struct packet*)arg;

    packet->src=region[8]; // src
    packet->dst=region[9]; // dst
    packet->optype=region[10]>>6; // 11 101010 -> 00000011
    printk("region[10]=%d, packet->optype=%d\n",region[10],packet->optype);
    operation=region[10]<<2; // 11101010 -> 10101000
    printk("<<2 operation=%d\n",operation);
    operation=operation>>2; // 10101000 -> 00101010
    printk(">>2 operation=%d\n",operation);
    packet->operation=operation; // 11 101010 -> 00101010
    packet->operand[0]=region[11];
    packet->operand[1]=region[12];

    home_packet=*packet;

    copy_to_user((struct packet*)arg,&home_packet,sizeof(home_packet));

    printk("recv_packet 받음 \n");
    printk("home_packet.src=%d\n",home_packet.src);
    printk("home_packet.dst=%d\n",home_packet.dst);
    printk("home_packet.optype=%d\n",home_packet.optype);
    printk("home_packet.operation=%d\n",home_packet.operation);
    printk("home_packet.operand[0]=%d\n",home_packet.operand[0]);
    printk("home_packet.operand[1]=%d\n",home_packet.operand[1]);

    return sizeof(home_packet);
}

int ipc_ioctl(struct inode* inode, struct file *fp, unsigned int cmd, unsigned long arg)
{
    int ret=0;

    printk("in ioctl\n");

    switch(cmd)
    {
    case IPC_SEND:
        printk("send_packet called\n");
        ret=send_packet(arg);
        break;
    case IPC_RECV:
        region[7]=0; // 메세지 받게 rx=0으로 세팅
        printk("recv_packet called\n");
        ret=recv_packet(arg);
        break;
    case IPC_LIST:
        printk("list_pass called\n");
        ret=list_pass(arg);
        break;
    default:
        printk("other cmd: %d\n",cmd);
        break;
    }
    return ret;
}

static int ipc_open(struct inode *inode, struct file *fp)
{
    if(!try_module_get(THIS_MODULE))
        return -ENODEV;
    printk("Device open\n");
    return 0;
}

static int ipc_read(struct file *fp, char *buf, size_t len, loff_t *lof)
{ 
    printk("ipc_read\n");

    //      copy_to_user(buf, gval, len);

    return 0;
}

static int ipc_write(struct file *fp, const char *buf, size_t len, loff_t *lof)
{ 
    printk("ipc_write\n");

    //    copy_from_user(gval, buf, len);

    return 0;
}

static int ipc_release(struct inode* inode, struct file *fp)
{
    module_put(THIS_MODULE);
    printk("Release Driver\n");
    return 0;
}

void vdev_reg_handler(int a,void* b) // 가상에서 디바이스로 넘어오는 레지스터 처리
{	// ACK용 처리 함수
    struct home_register temp;
    int i=0;

    printk("reg_handler2 called vdev to device\n");

    temp.rx=region[7];
    temp.src2=region[8];
    temp.dst2=region[9];
    temp.optypeop2=region[10];
    temp.operand2[0]=region[11];
    temp.operand2[1]=region[12];

    for(i=7; i<13; i++)
    {
        printk("region[%d]=%d\n",i,region[i]);
    }

    if(temp.dst2==0) // dst 가 device 이면 0
    {
        if(temp.optypeop2>=192 && temp.optypeop2<=195) // 브로드캐스팅 및 다른내용 있어도 저장  ACK 0 src=0 optype=11
        {
            dev_list[live_dev].addr=temp.src2; // src
            dev_list[live_dev].devicetype=temp.operand2[0]; // 여기에 디바이스타입 있음

            if(temp.optypeop2==192)
            {
                live_dev++;
                region[7]=0; // 다음 레지스터 가져오게 세팅
            }
            printk("live_dev=%d\n",live_dev);
        }
    }
}

/*
void reg_handler(unsigned long rcvdata)
{
        printk("reg_handler called\n");
        int i,j;
        byte *temp;
        printk("reg_handler called\n");

        temp=(unsigned char*)rcvdata;

        region[0]=1;
        region[1]=0;
        region[2]=255;
        region[3]=128; // 10000000
        region[4]=0;
        region[5]=0;

        printk("after region tx set 1 \n");

        int i;
        for(i=0; i<13; i++)
                printk("region[%d]=%d\n",i,region[i]);

}
*/
struct file_operations write_fops =
{
    .read = ipc_read,
    .write = ipc_write,
    .ioctl=ipc_ioctl,
    .open = ipc_open,
    .release = ipc_release,
};

static int controller_init(void)
{
    int size1;

    register_chrdev(BIABLO_DEV_MAJOR,BIABLO_DEV_NAME,&write_fops);
    printk("controller module init\n");

    size1 = request_reg_region(&region);

    printk("region size: %d\n", size1);

    init_devlist(); // dev_list 초기화 함수
    enroll_interruptHandler(fp);

    return 0;
}

static void controller_exit(void)
{
    unregister_chrdev(BIABLO_DEV_MAJOR,BIABLO_DEV_NAME);
    printk("controller module exit \n");

    unenroll_interruptHandler();
}

module_init(controller_init);
module_exit(controller_exit);

MODULE_LICENSE("Dual_BSD/GPL");

