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
	.dw   0x0801
	.dw   __next_line
        .dw   0x01a4        ; Line number
        .db   0x9E             ; SYS token
;       .db   <(((__sdcc_gs_init_startup / 10000) % 10) + '0)
;//        .db   (((__sdcc_gs_init_startup /  1000) % 10) + '0') 
;//        .db   (((__sdcc_gs_init_startup /   100) % 10) + '0')
;//        .db   (((__sdcc_gs_init_startup /    10) % 10) + '0')
;//        .db   (((__sdcc_gs_init_startup /     1) % 10) + '0')
	.db '2','0','6','1'
        .db   0x00             ; End of BASIC line
__next_line:
	.dw   0               ; BASIC end marker

__sdcc_gs_init_startup:
        ldx     #0xff
        txs
	lda 0x01
	and #0xfe
	sta 0x01	; clear LORAM to get 52K contiguos RAM

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
        jmp     .

__sdcc_indirect_jsr::
        jmp     [__TEMP]
