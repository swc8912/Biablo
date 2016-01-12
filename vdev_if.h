
#ifndef VDEV_IF_H_
#define VDEV_IF_H_

#include <linux/interrupt.h>

#define byte unsigned char

typedef void (*vir_handler)(int, void *);

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//register interface
////////////////////////////////////////////////////////////////
/*
* int request_reg_region(byte ** region)
* 레지스터 영역 요청
*
 *  인자 :
* 				region : 레지스터 포인터를 받을 변수의 주소값
 * 리턴 : 할당받은 레지스터 영역의 크기
 */
int request_reg_region(byte ** region);


////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////
//interrupt interface
////////////////////////////////////////////////////////////////

//IRQ RX : NO PARAM
#define VDEV_IRQ_RX 0x10



/*
* void enroll_interruptHandler(irq_handler_t fp);
*   인터럽트 핸들러 등록
*
 * 인자 :
* 				fp : 인터럽트 핸들러로 등록할 함수 포인
* 				typedef irqreturn_t (*irq_handler_t)(int, void *);
*
 */
void enroll_interruptHandler(vir_handler fp);

/*
* void unenroll_interruptHandler(irq_handler_t fp);
*   인터럽트 핸들러 해지
 */
void unenroll_interruptHandler();

#endif /* VDEV_IF_H_ */
