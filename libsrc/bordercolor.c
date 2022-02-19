#include <conio.h>
#include <c64.h>

unsigned char bordercolor(unsigned char c) __naked
{
  (void)c;
  __asm__("ldx _VIC_bordercolor");
  __asm__("sta _VIC_bordercolor");
  __asm__("txa");
  __asm__("ldx #0x00");
  __asm__("rts");
}
