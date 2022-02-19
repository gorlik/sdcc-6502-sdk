#include <conio.h>
#include <cbm_kernal.h>

unsigned char cgetc() __naked
{
  __asm__ ("L1:");
  __asm__ ("lda 0xc6"); // KEY_COUNT       ; Get number of characters
  __asm__ ("beq L1");
  __asm__ ("jsr _GETIN");
  __asm__ ("ldx #0x00");
  __asm__ ("rts");
}
