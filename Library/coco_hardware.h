#ifndef COCO_HARDWARE_H
#define COCO_HARDWARE_H

/* Useful hardware addresses for the Color Computer */
/*                                                  */
/* By tim lindner, 2007                             */
/* Added COCO3 defines - MRF 2009/03/19             */
/*                                                  */
/* This file is in the public domain                */

/* SAM TY adjusts the Memory Map mode */
#define SAM_TY_CLR ((char *)0xffde)
#define SAM_TY_SET ((char *)0xffdf)

/* SAM M1 and M0 adjusts the memory size */
#define SAM_M0_CLR ((char *)0xffda)
#define SAM_M0_SET ((char *)0xffdb)
#define SAM_M1_CLR ((char *)0xffdc)
#define SAM_M1_SET ((char *)0xffdd)

/* SAM R0 and R1 adjusts the MPU clock frequency */
#define SAM_R0_CLR ((char *)0xffd6)
#define SAM_R0_SET ((char *)0xffd7)
#define SAM_R1_CLR ((char *)0xffd8)
#define SAM_R1_SET ((char *)0xffd9)

/* SAM P1 adjusts the memory page number */
#define SAM_P1_CLR ((char *)0xffd4)
#define SAM_P1_SET ((char *)0xffd5)

/* SAM F0 thru F6 adjusts the video display starting address */
#define SAM_F0_CLR ((char *)0xffc6)
#define SAM_F0_SET ((char *)0xffc7)
#define SAM_F1_CLR ((char *)0xffc8)
#define SAM_F1_SET ((char *)0xffc9)
#define SAM_F2_CLR ((char *)0xffca)
#define SAM_F2_SET ((char *)0xffcb)
#define SAM_F3_CLR ((char *)0xffcc)
#define SAM_F3_SET ((char *)0xffcd)
#define SAM_F4_CLR ((char *)0xffce)
#define SAM_F4_SET ((char *)0xffcf)
#define SAM_F5_CLR ((char *)0xffd0)
#define SAM_F5_SET ((char *)0xffd1)
#define SAM_F6_CLR ((char *)0xffd2)
#define SAM_F6_SET ((char *)0xffd3)

/* SAM V0 thru V2 adjusts the video display mode */
#define SAM_V0_CLR ((char *)0xffc0)
#define SAM_V0_SET ((char *)0xffc1)
#define SAM_V1_CLR ((char *)0xffc2)
#define SAM_V1_SET ((char *)0xffc3)
#define SAM_V2_CLR ((char *)0xffc4)
#define SAM_V2_SET ((char *)0xffc5)

/* PIA 0 */
#define PIA0_DdRA ((char *)0xff00)
#define PIA0_CRA  ((char *)0xff01)
#define PIA0_DdRB ((char *)0xff02)
#define PIA0_CRB  ((char *)0xff03)

/* PIA 1 */
#define PIA1_DdRA ((char *)0xff20)
#define PIA1_CRA  ((char *)0xff21)
#define PIA1_DdRB ((char *)0xff22)
#define PIA1_CRB  ((char *)0xff23)

/* Text video buffer set by BASIC */
#define BASIC_VDG_TEXT ((char *)0x0400)

/* Disk Drives */
#define DSK_CONTROL ((char *)0xFF40) /* Control register */
#define DSK_CMDSTAT ((char *)0xFF48) /* Command/Status register */
#define DSK_TRACK   ((char *)0xFF49) /* Track register */
#define DSK_SECTOR  ((char *)0xFF4A) /* Sector register */
#define DSK_DATA    ((char *)0xFF4B) /* Data register */

#define DSK_STOP DSK_CONTROL=0

#ifdef COCO3
/* GIME Register Reference http://users.axess.com/twilight/sock/gime.html */

#define GIME_INIT0 ((char *)0xff90)   /* FF90 (65424) Initialization Register 0 - INIT0 */
#define GIME_INIT1 ((char *)0xff91)   /* FF91 (65425) Initialization Register 1 - INIT1 */
#define GIME_IRQENR ((char *)0xff92)  /* FF92 (65426) Interrupt request enable register - IRQENR */
#define GIME_FIRQENR ((char *)0xff93) /* FF93 (65427) Fast interrupt request enable register - FIRQENR */
#define GIME_TMRH ((char *)0xff94)    /* FF94 (65428) Timer register MSB */
#define GIME_TMRL ((char *)0xff95)    /* FF95 (65429) Timer register LSB */
#define GIME_RESV0 ((char *)0xff96)   /* FF96 (65430) Reserved */
#define GIME_RESV1 ((char *)0xff97)   /* FF97 (65431) Reserved */
#define GIME_VMODE ((char *)0xff98)   /* FF98 (65432) Video mode register - VMODE */
#define GIME_VRES ((char *)0xff99)    /* FF99 (65433) Video resolution register - VRES */
#define GIME_BRDR ((char *)0xff9a)    /* FF9A (65434) Border color register - BRDR */
#define GIME_RESV2 ((char *)0xff9b)   /* FF9B (65435) Reserved */
#define GIME_VSC ((char *)0xff9c)     /* FF9C (65436) Vertical scroll register - VSC */
#define GIME_VRAMH ((char *)0xff9d)   /* FF9D (65437) Vertical offset register MSB */
#define GIME_VRAML ((char *)0xff9e)   /* FF9E (65438) Vertical offset register LSB */
#define GIME_HVEN ((char *)0xff9f)    /* FF9F (65439) Horizontal offset register */

/* FFA0-FFA7 (65440-65447) MMU bank registers (task one) */
#define GIME_MMU1_BANK0 ((char *)0xffa0) /* Bank at $0000-$1FFF */
#define GIME_MMU1_BANK1 ((char *)0xffa1) /* Bank at $2000-$3FFF */
#define GIME_MMU1_BANK2 ((char *)0xffa2) /* Bank at $4000-$5FFF */
#define GIME_MMU1_BANK3 ((char *)0xffa3) /* Bank at $6000-$7FFF */
#define GIME_MMU1_BANK4 ((char *)0xffa4) /* Bank at $8000-$9FFF */
#define GIME_MMU1_BANK5 ((char *)0xffa5) /* Bank at $A000-$BFFF */
#define GIME_MMU1_BANK6 ((char *)0xffa6) /* Bank at $C000-$DFFF */
#define GIME_MMU1_BANK7 ((char *)0xffa7) /* Bank at $E000-$FFFF */

/* FFA8-FFAF (65448-65455) MMU bank registers (task two) */
#define GIME_MMU2_BANK0 ((char *)0xffa8) /* Bank at $0000-$1FFF */
#define GIME_MMU2_BANK1 ((char *)0xffa9) /* Bank at $2000-$3FFF */
#define GIME_MMU2_BANK2 ((char *)0xffaa) /* Bank at $4000-$5FFF */
#define GIME_MMU2_BANK3 ((char *)0xffab) /* Bank at $6000-$7FFF */
#define GIME_MMU2_BANK4 ((char *)0xffac) /* Bank at $8000-$9FFF */
#define GIME_MMU2_BANK5 ((char *)0xffad) /* Bank at $A000-$BFFF */
#define GIME_MMU2_BANK6 ((char *)0xffae) /* Bank at $C000-$DFFF */
#define GIME_MMU2_BANK7 ((char *)0xffaf) /* Bank at $E000-$FFFF */

/* FFB0-FFBF (65456-65471) Color palette registers */
#define GIME_PALETTE_COLOR0 ((char *)0xffb0)
#define GIME_PALETTE_COLOR1 ((char *)0xffb1)
#define GIME_PALETTE_COLOR2 ((char *)0xffb2)
#define GIME_PALETTE_COLOR3 ((char *)0xffb3)
#define GIME_PALETTE_COLOR4 ((char *)0xffb4)
#define GIME_PALETTE_COLOR5 ((char *)0xffb5)
#define GIME_PALETTE_COLOR6 ((char *)0xffb6)
#define GIME_PALETTE_COLOR7 ((char *)0xffb7)
#define GIME_PALETTE_COLOR8 ((char *)0xffb8)
#define GIME_PALETTE_COLOR9 ((char *)0xffb9)
#define GIME_PALETTE_COLOR10 ((char *)0xffba)
#define GIME_PALETTE_COLOR11 ((char *)0xffbb)
#define GIME_PALETTE_COLOR12 ((char *)0xffbc)
#define GIME_PALETTE_COLOR13 ((char *)0xffbd)
#define GIME_PALETTE_COLOR14 ((char *)0xffbe)
#define GIME_PALETTE_COLOR15 ((char *)0xffbf)

#define GIME_MPURATE_SLOW ((char *)0xffd8)
#define GIME_MPURATE_FAST ((char *)0xffd9)

#define GIME_MAPTYPE_ROM ((char *)0xffde)
#define GIME_MAPTYPE_RAM ((char *)0xffdf)

#endif /* coco3 */

#endif
