#include "libcontroller.h"

struct home_dev dev_list[254];

int main(void)
{
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

	devfd=device_open();
	if(devfd==0)
	{
		printf("open error\n");
		return 0;
	}
	printf("devfd=%d\n",devfd);

	while(1)
	{
		printf("0. broadcast 1. send 2. recv 3. listget 4. exit: ");
		scanf("%d",&cmd);

		if(cmd==0)
		{
			packet_set(&user_packet,0,255,2,0,0,0);
			ret=packet_send(devfd,user_packet);
			printf("send ret=%d\n",ret);
/*			ret=packet_recv(devfd,&recv_packet);
			printf("recv ret=%d\n");
		
			printf("recv_packet.src=%d\n",recv_packet.src);
			printf("recv_packet.dst=%d\n",recv_packet.dst);
			printf("recv_packet.optype=%d\n",recv_packet.optype);
			printf("recv_packet.operation=%d\n",recv_packet.operation);
			printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
			printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);*/
		}
		else if(cmd==1)
		{
			printf("input dev number: ");
			scanf("%d",&dst);
			printf("input type: ");
			scanf("%d",&type);
			printf("input dev operation: ");
			scanf("%d",&operation);
			printf("input operand[0]: ");
			scanf("%d",&operand1);
			printf("input operand[1]: ");
			scanf("%d",&operand2);
			
			packet_set(&user_packet,0,dst,type,operation,operand1,operand2);
			ret=packet_send(devfd,user_packet);
			printf("send ret=%d\n",ret);
		}
		else if(cmd==2)
		{
			ret=packet_recv(devfd,&recv_packet);
			printf("recv ret=%d\n");
		
			printf("recv_packet.src=%d\n",recv_packet.src);
			printf("recv_packet.dst=%d\n",recv_packet.dst);
			printf("recv_packet.optype=%d\n",recv_packet.optype);
			printf("recv_packet.operation=%d\n",recv_packet.operation);
			printf("recv_packet.operand[0]=%d\n",recv_packet.operand[0]);
			printf("recv_packet.operand[1]=%d\n",recv_packet.operand[1]);
		}
		else if(cmd==3)
		{
			get_devlist(devfd,dev_list);
			for(i=0; i<254; i++)
			{
				if(dev_list[i].addr==255)
					break;
				printf("dev_list[%d].addr=%d\n",i,dev_list[i].addr);
				printf("dev_list[%d].devicetype=%d\n",i,dev_list[i].devicetype);
			}
		}
		else if(cmd==4)
			break;
	}

	return 0;
}
