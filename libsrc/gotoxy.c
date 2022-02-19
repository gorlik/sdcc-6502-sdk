#include <conio.h>
#include <cbm_kernal.h>

void gotoxy(unsigned char x, unsigned char y) __naked
{
  (void)x;
  (void)y;
  __asm__("tay");
  __asm__("clc");
  __asm__("jmp _PLOT");
}
