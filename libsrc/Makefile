# sdcc SDK makefile

SDCCDIR=/mnt/share/local/sdcc420/bin
SDCC=$(SDCCDIR)/sdcc
SDAS=$(SDCCDIR)/sdas6500
MAKEBIN=$(SDCCDIR)/makebin

SDKDIR=..

SDCCTARGET=-mmos6502 -D__C64__
SDCCOPT=--max-allocs-per-node 25000 --opt-code-speed
SDCCDEBUG=--fverbose-asm --i-code-in-asm
SDKINC= -I $(SDKDIR)/include

CFLAGS = $(SDCCTARGET) $(SDCCOPT) $(SDKINC)
LDFLAGS = --out-fmt-ihx -mmos6502 --no-std-crt0 --code-loc 0x7ff --xram-loc 0x6000
CRT = c64_prg_crt0.rel c64_cart_crt0.rel
OBJECTS = putchar.rel kbhit.rel cgetc.rel cputc.rel cputs.rel gotoxy.rel bordercolor.rel clrscr.rel

all: $(CRT) $(OBJECTS)
	$(SDCCDIR)sdar rcSDs c64.lib $(OBJECTS)
	mkdir -p ../lib
	cp c64.lib ../lib
	cp c64_cart_crt0.rel ../lib
	cp c64_prg_crt0.rel  ../lib


clean:
	rm -rf *.ihx *.rel *.map *.noi *.asm *.lk *.sym *.lst *.lib ../lib

%.prg: %.ihx
	$(MAKEBIN) -o 2047 -p $< $@

%.rel: %.c
	$(SDCC) -c $(CFLAGS) $<

%.rel: %.s
	$(SDAS) -jxlospg $<
