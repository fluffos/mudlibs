// SilberLand MUDlib
//
// sys/wizard.h -- wizard defines
//
// $Date: 1998/02/26 11:50:09 $
/* $Revision: 1.2 $
 * $Log: wizard.h,v $
 * Revision 1.2  1998/02/26 11:50:09  Crea
 * new defines for 'mschau' handling (better syntax)
 *
 * Revision 1.1  1998/01/14 09:33:25  Crea
 * Initial revision
 *
 *
 */

#ifndef __WIZARD_H__
#define __WIZARD_H__

// Woody, brauchst Du die??

#define CH_MECHO        1
#define CH_ECHOALL      2


// neue Anzeigeflags bei mschau

#define RH_NFILENAME    4
#define RH_SIZE         8
#define RH_LIGHT        16
#define RH_TEMPERATURE  32
#define RH_CLONER       64
#define RH_TERRAIN      128
#define RH_IN_OUT       256
#define RH_NPC_HP       512
#define RH_NPC_SP       1024
#define RH_NPC_LVL      2048
#define RH_PLR_MV       4096
#define RH_NFNHDR       8192

// mschau-internes handling

#define RH_NAMES ({"fn", "sz", "li", "tmp", "cl", "ter", "io", \
                   "hp", "sp", "lv", "mv", "nfn"})
#define RH_NUM   ({4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192})
#define RH_MAX 8192

#endif /* __WIZARD_H__ */
