#ifndef _SYSCALL_H
#define _SYSCALL_H

#include "lib/common.h"

#define SYS_GET_TICK	4000
#define SYS_GET_KEY		4001
#define SYS_DRAW_POINT  4002
#define SYS_DRAW_LINE	4003
#define SYS_DRAW_FRAME	4004
#define SYS_GET_POINT   4005
#define SYS_YIELD       4006
#define SYS_SLEEP       4007
#define SYS_GETPID      4008
#define SYS_PUTC    	4009
#define SYS_FORK        4010
#define SYS_EXIT        4011
#define SYS_FLASH_SCREEN 4012
#define TIMER_HANDLERS_MAX 100


unsigned int system_get_tick();
char system_get_key(char);
int system_draw_point(int x,int y,int color);
int system_draw_line(int bx,int by,int ey,int color);
void system_flash_screen();
void system_draw_frame();
int __draw_point(int x,int y,int color);
int __draw_line(int bx,int by,int ey,int color);
void __draw_frame();
void __flash_screen();
char system_get_point(int,int);
char __get_point(int,int);
void system_yield();
void system_sleep(uint32_t);
uint32_t system_getpid();
void system_putc(char c);
int system_fork();
void system_exit();
typedef struct timer_handler{
    void (*ptr)(void);
    int used;
}timer_handler;

#endif
