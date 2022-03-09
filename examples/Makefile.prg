
SDCCDIR=/mnt/share/local/sdcc420/bin
SDCC=$(SDCCDIR)/sdcc
SDAS=$(SDCCDIR)/sdas6500
MAKEBIN=$(SDCCDIR)/makebin

SDKDIR=../../cbm-games/cbm-sdk


SDCCTARGET=-mmos6502
SDCCOPT=--max-allocs-per-node 25000 --opt-code-speed
SDCCDEBUG=--fverbose-asm --i-code-in-asm
SDKINC= -I $(SDKDIR)/include

SDCCFLAGS = $(SDCCTARGET) $(SDCCOPT) $(SDKINC)
SDCCLINKFLAGS = -L $(SDKDIR)/lib -mmos6502 --no-std-crt0 --code-loc 0x7ff
CRT=$(SDKDIR)/lib/c64_prg_crt0.rel
LIBS=c64.lib

OBJECTS = add32.rel

project.prg:

project.ihx: $(OBJECTS)
	$(SDCC) $(SDCCLINKFLAGS) $(CRT) $(LIBS) $(OBJECTS) -o $@

clean:
	rm -f *.ihx *.rel *.map *.noi *.asm *.lk *.sym *.lst

%.prg: %.ihx
	$(MAKEBIN) -o 2047 -p $< $@

%.rel: %.c *.h
	$(SDCC) -c $(SDCCFLAGS) $<

%.rel: %.s
	$(SDAS) -jxlosp $<
