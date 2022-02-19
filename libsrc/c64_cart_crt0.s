	.module crt0

	;; Ordering of segments for the linker.
        .area HOME    (CODE)
        .area GSINIT  (CODE)
        .area GSFINAL (CODE)
        .area CSEG    (CODE)
        .area XINIT   (CODE)
        .area CONST   (CODE)
        .area DSEG    (PAG)
        .area OSEG    (PAG, OVR)
        .area XSEG
        .area XISEG
        .area DSEG    (PAG)

        .area GSINIT
	.dw	__cart_init           ;Cold start
	.dw	0xFEBC		;Warm start, default calls NMI exit.
	.db	0xC3,0xC2,0xCD,0x38,0x30 ;magic to identify cartridge

__cart_init:
	jsr	0xFF84		;Init. I/O
	jsr	0xFF87		;Init. RAM
	jsr	0xFF8A		;Restore vectors
	jsr	0xFF81		;Init. screen
__sdcc_gs_init_startup:
        ldx     #0xff
        txs
;        ldx     #0x01         ; MSB of stack ptr
;        stx     __BASEPTR+1

        jsr     __sdcc_external_startup
        beq     __sdcc_init_data
        jmp     __sdcc_program_startup

__sdcc_init_data:
; _m6502_genXINIT() start
        lda #<s_XINIT
        sta ___memcpy_PARM_2
        lda #>s_XINIT
        sta ___memcpy_PARM_2+1
        lda #<l_XINIT
        sta ___memcpy_PARM_3
        lda #>l_XINIT
        sta ___memcpy_PARM_3+1
        lda #<s_XISEG
        ldx #>s_XISEG
        jsr ___memcpy
; _m6502_genXINIT() end

; _m6502_genXSEG() start
        lda #0x00
        sta _memset_PARM_2
        sta _memset_PARM_2+1
        lda #<l_XSEG
        sta _memset_PARM_3
        lda #>l_XSEG
        sta _memset_PARM_3+1
        lda #<s_XSEG
        ldx #>s_XSEG
        jsr _memset
; _m6502_genXSEG() end
	lda #14
	jsr 0xffd2

        .area GSFINAL
        jmp     __sdcc_program_startup

        .area CSEG
__sdcc_program_startup:
        jsr     _main
infloop:
        jmp     infloop
__sdcc_indirect_jsr::
        jmp     [__TEMP]

