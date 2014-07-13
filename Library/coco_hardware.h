/* Useful hardware addresses for the Color Computer */
/*                                                  */
/* By tim lindner, 2007                             */
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

