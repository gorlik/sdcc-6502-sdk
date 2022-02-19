/*****************************************************************************/
/*                                                                           */
/*                                  _vic2.h                                  */
/*                                                                           */
/*                Internal include file, do not use directly                 */
/*                                                                           */
/*                                                                           */
/*                                                                           */
/* (C) 1998-2012, Ullrich von Bassewitz                                      */
/*                Roemerstrasse 52                                           */
/*                D-70794 Filderstadt                                        */
/* EMail:         uz@cc65.org                                                */
/*                                                                           */
/*                                                                           */
/* This software is provided 'as-is', without any expressed or implied       */
/* warranty.  In no event will the authors be held liable for any damages    */
/* arising from the use of this software.                                    */
/*                                                                           */
/* Permission is granted to anyone to use this software for any purpose,     */
/* including commercial applications, and to alter it and redistribute it    */
/* freely, subject to the following restrictions:                            */
/*                                                                           */
/* 1. The origin of this software must not be misrepresented; you must not   */
/*    claim that you wrote the original software. If you use this software   */
/*    in a product, an acknowledgment in the product documentation would be  */
/*    appreciated but is not required.                                       */
/* 2. Altered source versions must be plainly marked as such, and must not   */
/*    be misrepresented as being the original software.                      */
/* 3. This notice may not be removed or altered from any source              */
/*    distribution.                                                          */
/*                                                                           */
/*****************************************************************************/



#ifndef __VIC2_H
#define __VIC2_H



/* Define a structure with the vic register offsets. In cc65 mode, there
** are aliases for the field accessible as arrays.
*/
#if __CC65_STD__ == __CC65_STD_CC65__
struct __vic2 {
    union {
        struct {
            unsigned char   spr0_x;         /* Sprite 0, X coordinate */
            unsigned char   spr0_y;         /* Sprite 0, Y coordinate */
            unsigned char   spr1_x;         /* Sprite 1, X coordinate */
            unsigned char   spr1_y;         /* Sprite 1, Y coordinate */
            unsigned char   spr2_x;         /* Sprite 2, X coordinate */
            unsigned char   spr2_y;         /* Sprite 2, Y coordinate */
            unsigned char   spr3_x;         /* Sprite 3, X coordinate */
            unsigned char   spr3_y;         /* Sprite 3, Y coordinate */
            unsigned char   spr4_x;         /* Sprite 4, X coordinate */
            unsigned char   spr4_y;         /* Sprite 4, Y coordinate */
            unsigned char   spr5_x;         /* Sprite 5, X coordinate */
            unsigned char   spr5_y;         /* Sprite 5, Y coordinate */
            unsigned char   spr6_x;         /* Sprite 6, X coordinate */
            unsigned char   spr6_y;         /* Sprite 6, Y coordinate */
            unsigned char   spr7_x;         /* Sprite 7, X coordinate */
            unsigned char   spr7_y;         /* Sprite 7, Y coordinate */
        };
        struct {
            unsigned char   x;              /* X coordinate */
            unsigned char   y;              /* Y coordinate */
        } spr_pos[8];
    };
    unsigned char           spr_hi_x;       /* High bits of X coordinate */
    unsigned char           ctrl1;          /* Control register 1 */
    unsigned char           rasterline;     /* Current raster line */
    union {
        struct {
            unsigned char   strobe_x;       /* Light pen, X position */
            unsigned char   strobe_y;       /* Light pen, Y position */
        };
        struct {
            unsigned char   x;              /* Light pen, X position */
            unsigned char   y;              /* Light pen, Y position */
        } strobe;
    };
    unsigned char           spr_ena;        /* Enable sprites */
    unsigned char           ctrl2;          /* Control register 2 */
    unsigned char           spr_exp_y;      /* Expand sprites in Y dir */
    unsigned char           addr;           /* Address of chargen and video ram */
    unsigned char           irr;            /* Interrupt request register */
    unsigned char           imr;            /* Interrupt mask register */
    unsigned char           spr_bg_prio;    /* Priority to background */
    unsigned char           spr_mcolor;     /* Sprite multicolor bits */
    unsigned char           spr_exp_x;      /* Expand sprites in X dir */
    unsigned char           spr_coll;       /* Sprite/sprite collision reg */
    unsigned char           spr_bg_coll;    /* Sprite/background collision reg */
    unsigned char           bordercolor;    /* Border color */
    union {
        struct {
            unsigned char   bgcolor0;       /* Background color 0 */
            unsigned char   bgcolor1;       /* Background color 1 */
            unsigned char   bgcolor2;       /* Background color 2 */
            unsigned char   bgcolor3;       /* Background color 3 */
        };
        unsigned char       bgcolor[4];     /* Background colors */
    };
    union {
        struct {
            unsigned char   spr_mcolor0;    /* Color 0 for multicolor sprites */
            unsigned char   spr_mcolor1;    /* Color 1 for multicolor sprites */
        };
        /* spr_color is already used ... */
        unsigned char       spr_mcolors[2]; /* Color for multicolor sprites */
    };
    union {
        struct {
            unsigned char   spr0_color;     /* Color sprite 0 */
            unsigned char   spr1_color;     /* Color sprite 1 */
            unsigned char   spr2_color;     /* Color sprite 2 */
            unsigned char   spr3_color;     /* Color sprite 3 */
            unsigned char   spr4_color;     /* Color sprite 4 */
            unsigned char   spr5_color;     /* Color sprite 5 */
            unsigned char   spr6_color;     /* Color sprite 6 */
            unsigned char   spr7_color;     /* Color sprite 7 */
        };
        unsigned char       spr_color[8];   /* Colors for the sprites */
    };

    /* The following ones are only valid in the C128: */
    unsigned char           x_kbd;          /* Additional keyboard lines */
    unsigned char           clock;          /* Clock switch bit */
};
#else
struct __vic2 {
    unsigned char           spr0_x;         /* Sprite 0, X coordinate */
    unsigned char           spr0_y;         /* Sprite 0, Y coordinate */
    unsigned char           spr1_x;         /* Sprite 1, X coordinate */
    unsigned char           spr1_y;         /* Sprite 1, Y coordinate */
    unsigned char           spr2_x;         /* Sprite 2, X coordinate */
    unsigned char           spr2_y;         /* Sprite 2, Y coordinate */
    unsigned char           spr3_x;         /* Sprite 3, X coordinate */
    unsigned char           spr3_y;         /* Sprite 3, Y coordinate */
    unsigned char           spr4_x;         /* Sprite 4, X coordinate */
    unsigned char           spr4_y;         /* Sprite 4, Y coordinate */
    unsigned char           spr5_x;         /* Sprite 5, X coordinate */
    unsigned char           spr5_y;         /* Sprite 5, Y coordinate */
    unsigned char           spr6_x;         /* Sprite 6, X coordinate */
    unsigned char           spr6_y;         /* Sprite 6, Y coordinate */
    unsigned char           spr7_x;         /* Sprite 7, X coordinate */
    unsigned char           spr7_y;         /* Sprite 7, Y coordinate */
    unsigned char           spr_hi_x;       /* High bits of X coordinate */
    unsigned char           ctrl1;          /* Control register 1 */
    unsigned char           rasterline;     /* Current raster line */
    unsigned char           strobe_x;       /* Light pen, X position */
    unsigned char           strobe_y;       /* Light pen, Y position */
    unsigned char           spr_ena;        /* Enable sprites */
    unsigned char           ctrl2;          /* Control register 2 */
    unsigned char           spr_exp_y;      /* Expand sprites in Y dir */
    unsigned char           addr;           /* Address of chargen and video ram */
    unsigned char           irr;            /* Interrupt request register */
    unsigned char           imr;            /* Interrupt mask register */
    unsigned char           spr_bg_prio;    /* Priority to background */
    unsigned char           spr_mcolor;     /* Sprite multicolor bits */
    unsigned char           spr_exp_x;      /* Expand sprites in X dir */
    unsigned char           spr_coll;       /* Sprite/sprite collision reg */
    unsigned char           spr_bg_coll;    /* Sprite/background collision reg */
    unsigned char           bordercolor;    /* Border color */
    unsigned char           bgcolor0;       /* Background color 0 */
    unsigned char           bgcolor1;       /* Background color 1 */
    unsigned char           bgcolor2;       /* Background color 2 */
    unsigned char           bgcolor3;       /* Background color 3 */
    unsigned char           spr_mcolor0;    /* Color 0 for multicolor sprites */
    unsigned char           spr_mcolor1;    /* Color 1 for multicolor sprites */
    unsigned char           spr0_color;     /* Color sprite 0 */
    unsigned char           spr1_color;     /* Color sprite 1 */
    unsigned char           spr2_color;     /* Color sprite 2 */
    unsigned char           spr3_color;     /* Color sprite 3 */
    unsigned char           spr4_color;     /* Color sprite 4 */
    unsigned char           spr5_color;     /* Color sprite 5 */
    unsigned char           spr6_color;     /* Color sprite 6 */
    unsigned char           spr7_color;     /* Color sprite 7 */

    /* The following ones are only valid in the C128: */
    unsigned char           x_kbd;          /* Additional keyboard lines */
    unsigned char           clock;          /* Clock switch bit */
};
#endif

#ifndef VIC_BASE
#define VIC_BASE 0xd000
#endif

unsigned char __at (VIC_BASE+0x00) VIC_spr0_x;      /* Sprite 0, X coordinate */
unsigned char __at (VIC_BASE+0x01) VIC_spr0_y;      /* Sprite 0, Y coordinate */
unsigned char __at (VIC_BASE+0x02) VIC_spr1_x;      /* Sprite 1, X coordinate */
unsigned char __at (VIC_BASE+0x03) VIC_spr1_y;      /* Sprite 1, Y coordinate */
unsigned char __at (VIC_BASE+0x04) VIC_spr2_x;      /* Sprite 2, X coordinate */
unsigned char __at (VIC_BASE+0x05) VIC_spr2_y;      /* Sprite 2, Y coordinate */
unsigned char __at (VIC_BASE+0x06) VIC_spr3_x;      /* Sprite 3, X coordinate */
unsigned char __at (VIC_BASE+0x07) VIC_spr3_y;      /* Sprite 3, Y coordinate */
unsigned char __at (VIC_BASE+0x08) VIC_spr4_x;      /* Sprite 4, X coordinate */
unsigned char __at (VIC_BASE+0x09) VIC_spr4_y;      /* Sprite 4, Y coordinate */
unsigned char __at (VIC_BASE+0x0a) VIC_spr5_x;      /* Sprite 5, X coordinate */
unsigned char __at (VIC_BASE+0x00) VIC_spr5_y;      /* Sprite 5, Y coordinate */
unsigned char __at (VIC_BASE+0x00) VIC_spr6_x;      /* Sprite 6, X coordinate */
unsigned char __at (VIC_BASE+0x0d) VIC_spr6_y;      /* Sprite 6, Y coordinate */
unsigned char __at (VIC_BASE+0x0e) VIC_spr7_x;      /* Sprite 7, X coordinate */
unsigned char __at (VIC_BASE+0x0f) VIC_spr7_y;      /* Sprite 7, Y coordinate */
unsigned char __at (VIC_BASE+0x10) VIC_spr_hi_x;    /* High bits of X coordinate */
unsigned char __at (VIC_BASE+0x11) VIC_ctrl1;       /* Control register 1 */
unsigned char __at (VIC_BASE+0x12) VIC_rasterline;  /* Current raster line */
unsigned char __at (VIC_BASE+0x13) VIC_strobe_x;    /* Light pen, X position */
unsigned char __at (VIC_BASE+0x14) VIC_strobe_y;    /* Light pen, Y position */
unsigned char __at (VIC_BASE+0x15) VIC_spr_ena;     /* Enable sprites */
unsigned char __at (VIC_BASE+0x16) VIC_ctrl2;       /* Control register 2 */
unsigned char __at (VIC_BASE+0x17) VIC_spr_exp_y;   /* Expand sprites in Y dir */
unsigned char __at (VIC_BASE+0x18) VIC_addr;        /* Address of chargen and video ram */
unsigned char __at (VIC_BASE+0x19) VIC_irr;         /* Interrupt request register */
unsigned char __at (VIC_BASE+0x1a) VIC_imr;         /* Interrupt mask register */
unsigned char __at (VIC_BASE+0x1b) VIC_spr_bg_prio; /* Priority to background */
unsigned char __at (VIC_BASE+0x1c) VIC_spr_mcolor;  /* Sprite multicolor bits */
unsigned char __at (VIC_BASE+0x1d) VIC_spr_exp_x;   /* Expand sprites in X dir */
unsigned char __at (VIC_BASE+0x1e) VIC_spr_coll;    /* Sprite/sprite collision reg */
unsigned char __at (VIC_BASE+0x1f) VIC_spr_bg_coll; /* Sprite/background collision reg */
unsigned char __at (VIC_BASE+0x20) VIC_bordercolor; /* Border color */
unsigned char __at (VIC_BASE+0x21) VIC_bgcolor0;    /* Background color 0 */
unsigned char __at (VIC_BASE+0x22) VIC_bgcolor1;    /* Background color 1 */
unsigned char __at (VIC_BASE+0x23) VIC_bgcolor2;    /* Background color 2 */
unsigned char __at (VIC_BASE+0x24) VIC_bgcolor3;    /* Background color 3 */
unsigned char __at (VIC_BASE+0x25) VIC_spr_mcolor0; /* Color 0 for multicolor sprites */
unsigned char __at (VIC_BASE+0x26) VIC_spr_mcolor1; /* Color 1 for multicolor sprites */
unsigned char __at (VIC_BASE+0x27) VIC_spr0_color;  /* Color sprite 0 */
unsigned char __at (VIC_BASE+0x28) VIC_spr1_color;  /* Color sprite 1 */
unsigned char __at (VIC_BASE+0x29) VIC_spr2_color;  /* Color sprite 2 */
unsigned char __at (VIC_BASE+0x2a) VIC_spr3_color;  /* Color sprite 3 */
unsigned char __at (VIC_BASE+0x2b) VIC_spr4_color;  /* Color sprite 4 */
unsigned char __at (VIC_BASE+0x2c) VIC_spr5_color;  /* Color sprite 5 */
unsigned char __at (VIC_BASE+0x2d) VIC_spr6_color;  /* Color sprite 6 */
unsigned char __at (VIC_BASE+0x2e) VIC_spr7_color;  /* Color sprite 7 */

    /* The following ones are only valid in the C128: */
unsigned char __at (VIC_BASE+0x2f) VIC_x_kbd;       /* Additional keyboard lines */
unsigned char __at (VIC_BASE+0x30) VIC_clock;       /* Clock switch bit */

/* End of _vic2.h */
#endif
