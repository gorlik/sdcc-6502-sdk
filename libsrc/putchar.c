#include <stdio.h>

int putchar(int c) __naked
{
  (void)c;

  __asm__ (".globl _cputc");
  __asm__ ("pha");
  __asm__ ("jsr _cputc");
  __asm__ ("ldx #0x00");
  __asm__ ("pla");
  __asm__ ("rts");
}
