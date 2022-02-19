#ifndef _CBM_KERNAL_H
#define _CBM_KERNAL_H

#define kernal_entry(name, addr) __at addr void(*name)(void)

#if defined(__C64__) || defined(__C128__) || defined(__C16__)
kernal_entry(CINT,   0xff81);
kernal_entry(IOINIT, 0xff84);
kernal_entry(RAMTAS, 0xff87);
#elif defined(__VIC20__)
kernal_entry(CINT,   0xe518); // No entries are in the Kernal jump table of the VIC-20 for these three (3) functions.
kernal_entry(IOINIT, 0xfdf9); // The entries for these functions have been set to point directly to the functions
kernal_entry(RAMTAS, 0xfd8d); // in the Kernal, to maintain compatibility with the other Commodore platforms.
#elif defined(__CBM510__) || defined (__CBM610__)
kernal_entry(CINT,   0xff7e); // No entries are in the Kernal jump table of the VIC-20 for these three (3) functions.
kernal_entry(IOINIT, 0xff7b); // The entries for these functions have been set to point directly to the functions
#endif

#if defined(__VIC20__) || defined(__C64__) || defined(__C128__) || defined(__C16__)
kernal_entry(RESTOR, 0xff8a);
kernal_entry(VECTOR, 0xff8d);
#elif defined(__CBM510__) || defined(__CBM610__)
kernal_entry(RESTOR, 0xff84);
kernal_entry(VECTOR, 0xff87);
#endif

#if defined(__CBM510__) || defined(__CBM610__) || defined(__VIC20__) || defined(__C64__) || defined(__C128__) || defined(__C16__)
kernal_entry(SETMSG, 0xff90);
kernal_entry(SECOND, 0xff93);
kernal_entry(TKSA,   0xff96);
kernal_entry(MEMTOP, 0xff99);
kernal_entry(MEMBOT, 0xff9c);
kernal_entry(SCNKEY, 0xff9f);
kernal_entry(SETTMO, 0xffa2);
kernal_entry(ACPTR,  0xffa5);
kernal_entry(CIOUT,  0xffa8);
kernal_entry(UNTLK,  0xffab);
kernal_entry(UNLSN,  0xffae);
kernal_entry(LISTEN, 0xffb1);
kernal_entry(TALK,   0xffb4);
kernal_entry(READST, 0xffb7);
kernal_entry(SETLFS, 0xffba);
kernal_entry(SETNAM, 0xffbd);
kernal_entry(OPEN,   0xffc0);
kernal_entry(CLOSE,  0xffc3);
#endif

// Available on all platforms including PET
kernal_entry(CHKIN,  0xffc6);
kernal_entry(CKOUT,  0xffc9);
kernal_entry(CHKOUT, 0xffc9);
kernal_entry(CLRCH,  0xffcc);
kernal_entry(CLRCHN, 0xffcc);
kernal_entry(BASIN,  0xffcf);
kernal_entry(CHRIN,  0xffcf);
kernal_entry(BSOUT,  0xffd2);
kernal_entry(CHROUT, 0xffd2);

#if defined(__CBM510__) || defined(__CBM610__) || defined(__VIC20__) || defined(__C64__) || defined(__C128__) || defined(__C16__)
kernal_entry(LOAD,   0xffd5);
kernal_entry(SAVE,   0xffd8);
kernal_entry(SETTIM, 0xffdb);
kernal_entry(RDTIM,  0xffde);
#endif

// Available on all platforms including PET
kernal_entry(STOP,   0xffe1);
kernal_entry(GETIN,  0xffe4);
kernal_entry(CLALL,  0xffe7);
kernal_entry(UDTIM,  0xffea);

#if defined(__CBM510__) || defined(__CBM610__) || defined(__VIC20__) || defined(__C64__) || defined(__C128__) || defined(__C16__)
kernal_entry(SCREEN, 0xffed);
kernal_entry(PLOT,   0xfff0);
kernal_entry(IOBASE, 0xfff3);
#endif

#endif
