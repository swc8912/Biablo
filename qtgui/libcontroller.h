#ifndef LIBCONTROLLER_H
#define LIBCONTROLLER_H

#endif // LIBCONTROLLER_H

#include <stdio.h>
#include <unistd.h>
#include <sys/fcntl.h>
#include <sys/ioctl.h>

#define IPC_IOCTL_NUM 100
#define IPC_OPEN        _IOWR(IPC_IOCTL_NUM,1,unsigned long*)
#define IPC_CLOSE       _IOWR(IPC_IOCTL_NUM,2,unsigned long*)
#define IPC_SEND        _IOWR(IPC_IOCTL_NUM,3,unsigned long*)
#define IPC_RECV        _IOWR(IPC_IOCTL_NUM,4,unsigned long*)
#define IPC_LIST        _IOWR(IPC_IOCTL_NUM,5,unsigned long*)

#define BIABLO_DEV_NAME "/dev/biablo"
#define byte unsigned char

struct packet
{
        unsigned char src;
        unsigned char dst;
        unsigned char optype:2;
        unsigned char operation:6;
        unsigned char operand[2];
};

struct home_dev // 현재 연결된 디바이스 구조체
{
        unsigned char addr; // 디바이스 번호
        unsigned char devicetype; // 디바이스 타입: 가전제품 종류
        unsigned char operation[3][2]; // 1 2 3번 타입의 값들을 2바이트로 저장
};

struct packet home_packet;
struct home_dev dev_list[254];

int menu;
int number;

int devfd;
int cmd;
int ret;
struct packet user_packet;
struct packet recv_packet;

int i=0;
int dst;
int type;
int operation;
int operand1,operand2;

int device_open()
{
        int devfd;
        int ret;

        devfd=open(BIABLO_DEV_NAME,O_RDWR);
        if(!devfd)
        {
                printf("devfd open error\n");
                return -1;
        }


        return devfd;
}

int device_close(int devfd)
{
        int ret;

        printf("device_close\n");
        close(devfd);
        return 0;
}

int packet_send(int devfd,struct packet data) // 값만 넘겨주면 됨
{
        int ret;
        int i=0;

        home_packet=data;
//	memcpy(&home_packet,&data,sizeof(struct packet));
/*
        printf("devfd=%d\n",devfd);
        printf("home_packet.src=%d\n",home_packet.src);
        printf("home_packet.dst=%d\n",home_packet.dst);
        printf("home_packet.optype=%d\n",home_packet.optype);
        printf("home_packet.operation=%d\n",home_packet.operation);
        printf("home_packet.operand[0]=%d\n",home_packet.operand[0]);
        printf("home_packet.operand[1]=%d\n",home_packet.operand[1]);
*/
        printf("packet_send go \n");

        ret=ioctl(devfd,IPC_SEND,(unsigned long)&home_packet);
        printf("ipc_send ret=%d\n",ret);

        return ret;
}

int packet_recv(int devfd,struct packet *data) // 받아야 되서 포인터로
{
        int ret;

        ret=ioctl(devfd,IPC_RECV,(unsigned long)data);
        printf("packet_recv go \n");
        return ret;
}

void packet_set(struct packet* home_packet,byte src,byte dst,byte optype,byte operation,byte operand1,
                byte operand2)
{
        home_packet->src=src;
        home_packet->dst=dst;
        home_packet->optype=optype;
        home_packet->operation=operation;
        home_packet->operand[0]=operand1;
        home_packet->operand[1]=operand2;
}

void get_devlist(int devfd,struct home_dev *home_list)
{
        int ret;

        ret=ioctl(devfd,IPC_LIST,(unsigned long)home_list);
}
