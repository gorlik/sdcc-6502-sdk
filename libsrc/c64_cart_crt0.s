	.module crt0

	; Ordering of segments for the linker.
        .area _CODE
        .area GSINIT
        .area GSFINAL
        .area CODE
        .area RODATA
        .area XINIT
	.area _DATA
        .area DATA
        .area BSS
        .area ZP      (PAG)
        .area OSEG    (PAG, OVR)

        .area GSINIT
	.dw	__cart_init     ; Cold start
	.dw	0xFEBC		; Warm start, default calls NMI exit.
	.db	0xC3,0xC2,0xCD,0x38,0x30 ; "CBM80" magic to identify cartridge

__cart_init:
        ldx     #0xff
        txs
	jsr	0xFF84		; Init. I/O
	jsr	0xFF87		; Init. RAM
	jsr	0xFF8A		; Restore vectors
	jsr	0xFF81		; Init. screen

__sdcc_gs_init_startup:
;        ldx     #0x01         ; MSB of stack ptr
;        stx     __BASEPTR+1

; initialize DATA
        lda #<s_XINIT
        sta *___memcpy_PARM_2
        lda #>s_XINIT
        sta *___memcpy_PARM_2+1
        lda #<l_XINIT
        sta *___memcpy_PARM_3
        lda #>l_XINIT
        sta *___memcpy_PARM_3+1
        lda #<s_DATA
        ldx #>s_DATA
        jsr ___memcpy

; clear BSS
        lda #0x00
        sta *_memset_PARM_2
        lda #<l_BSS
        sta *_memset_PARM_3
        lda #>l_BSS
        sta *_memset_PARM_3+1
        lda #<s_BSS
        ldx #>s_BSS
        jsr _memset

; switch to lowercase
	lda #14
	jsr 0xffd2

        .area GSFINAL
__sdcc_program_startup:
        jsr     _main
        jmp     .
