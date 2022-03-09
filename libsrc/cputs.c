#include <conio.h>

void cputs(const unsigned char *s)
{
  while(*s)
	cputc(*s++);
}
