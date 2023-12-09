# sdcc C64 Makefile
TARGETS = hello.prg hello.bin

OBJECTS = hello.rel
LIBS = c64.lib

# toolchain location
SDCCDIR=/usr
# SDK location
SDKDIR=..

SDCCTARGET = -mmos6502 -D__C64__
SDCCOPT = --max-allocs-per-node 25000 --opt-code-speed
SDCCDEBUG = --fverbose-asm --i-code-in-asm
SDKINC = -I $(SDKDIR)/include

CFLAGS = $(SDCCTARGET) $(SDCCOPT) $(SDKINC)
LDFLAGS = -L $(SDKDIR)/lib -mmos6502 --no-std-crt0

CRTPRG = $(SDKDIR)/lib/c64_prg_crt0.rel
CRTCART =  $(SDKDIR)/lib/c64_cart_crt0.rel


SDCC=$(SDCCDIR)/bin/sdcc
SDAS=$(SDCCDIR)/bin/sdas6500
SDAR=$(SDCCDIR)/bin/sdar
MAKEBIN=$(SDCCDIR)/bin/makebin

all: $(TARGETS)

#project.ihx: $(OBJECTS)
#	$(SDCC) $(SDCCLINKFLAGS) $(CRT) $(LIBS) $(OBJECTS) -o $@

clean:
	rm -f *.ihx *.rel *.map *.noi *.asm *.lk *.sym *.lst *.prg *.bin

.PRECIOUS: %.rel %.ihx

%.bin: $(OBJECTS)
	$(SDCC) $(LDFLAGS) --code-loc 0x8000 --data-loc 0x12 --xram-loc 0x1000 $(CRTCART) -l $(LIBS) $< -o $@.ihx
	$(MAKEBIN) -o 0x8000 -s 0xc000 $@.ihx $@


%.prg: $(OBJECTS)
	$(SDCC) $(LDFLAGS) --code-loc 0x07ff --data-loc 0x12 --xram-loc 0xc000 $(CRTPRG) -l $(LIBS) $< -o $@.ihx
	$(MAKEBIN) -o 0x07ff -s 0xd000 -p $@.ihx $@

%.rel: %.c
	$(SDCC) $(CFLAGS) -c -o $@ $<

%.rel: %.s
	$(SDAS) -jxlosp $@ $<
