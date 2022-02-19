#include <conio.h>

unsigned char kbhit(void) __naked
{
__asm__("ldx     #0");   //          ; High byte of return is always zero
__asm__("lda     0xc6"); // KEY_COUNT       ; Get number of characters
__asm__("beq     L9");
__asm__("lda     #1");
__asm__("L9:     rts");
}
