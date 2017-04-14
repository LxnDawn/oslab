#include "lib/common.h"
//#include "lib/mytimer.h"
#include <lib/serial.h>
#include <lib/video.h>
//static void (*do_timer)(void);
static void (*do_keyboard)(int);
void
set_timer_intr_handler( void (*ptr)(void) ) {
}
void
set_keyboard_intr_handler( void (*ptr)(int) ) {
	do_keyboard = ptr;
}
extern void press_key();
extern void do_timer();
void do_syscall(struct TrapFrame *);
/* TrapFrame的定义在include/x86/memory.h
 * 请仔细理解这段程序的含义，这些内容将在后续的实验中被反复使用。 */
void
irq_handle(struct TrapFrame *tf) {
	//printf("%d\n",tf->irq);
	if(tf->irq < 1000) {
		if(tf->irq == -1) {
			//printk("%s, %d: Unhandled exception!\n", __FUNCTION__, __LINE__);
		}
		else {
			//printk("%s, %d: Unexpected exception #%d!\n", __FUNCTION__, __LINE__, tf->irq);
		}
	}

	if (tf->irq == 0x80) {
		do_syscall(tf);
	}
	else if (tf->irq == 1000) {
		do_timer();
	} else if (tf->irq == 1001) {
		uint32_t code = inb(0x60);
		uint32_t val = inb(0x61);
		outb(0x61, val | 0x80);
		outb(0x61, val);
		press_key(code);
	} else {

	}
}

