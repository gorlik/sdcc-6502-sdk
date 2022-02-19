#include <conio.h>
#include <cbm_kernal.h>

void clrscr(void) __naked
{
  __asm__("lda #147");
  __asm__("jmp _CHROUT");
}
