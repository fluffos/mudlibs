#ifndef __VT_100_H__
#define __VT_100_H__

#include <ansi.h>

#ifndef ESC
#define ESC	""			/* Escape (^[ )                      */
#endif
#define CSI     ESC+"["

#define	 VT_CLS		CSI+"2J"+CSI+"H"           /* clear screen + 0/0*/
#define  VT_CLEAR       CSI+"2J"                   /* clear screen      */
#define  VT_CLEART      CSI+"1J"                   /* clear to cursor   */
#define  VT_CLEARF      CSI+"0J"                   /* clear from cursor */
#define  VT_CEOL        CSI+"K"                    /* clear to EOL      */
#define  VT_SC          ESC+""+7                   /* save cursor       */
#define  VT_RC          ESC+""+8                   /* restore cursor    */
#define  VT_PC(l,c)	CSI+(l)+";"+(c)+"H"        /* set cursor pos    */
#define  VT_MARGS(t,b)  CSI+(t)+";"+(b)+"r"        /* set margins       */

#define  VT_TA(a)       CSI+(a)+"m"                /* set text-attr     */
#define  VT_TA_AO       CSI+"0m"                   /* text-attr all out */
#define  VT_TA_B        CSI+"1m"                   /* text-attr bold    */
#define  VT_TA_U        CSI+"4m"                   /* text-attr underlin*/
#define  VT_TA_FO       CSI+"5m"                   /* flash on          */
#define  VT_TA_I        CSI+"7m"                   /* invers            */
#define  VT_TA_C        CSI+"8m"                   /* covered           */

#define  VT_NWRAP	CSI+"?7l"                  /* No autowrap       */
#define  VT_WRAP	CSI+"?7h"                  /* Autowrap 	        */

#define  VT_INS	        CSI+"4h"                   /* Insert characters */
#define  VT_REP	        CSI+"4l"                   /* Replace characters*/

#define	VT_DEL_L(l)	CSI+(l)+"M"                /* Delete l lines    */
#define	VT_INS_L(l)	CSI+(l)+"L"                /* Insert l lines    */
#define	VT_DEL_C(l)	CSI+(l)+"P"                /* Delete l chars    */

#define	VT_CUR_R(n)	CSI+(n)+"C"                /* move cursor right */
#define	VT_CUR_L(n)	CSI+(n)+"D"                /* move cursor left  */
#define	VT_CUR_U(n)	CSI+(n)+"A"                /* move cursor up    */
#define	VT_CUR_D(n)	CSI+(n)+"B"                /* move cursor down  */

/* Foreground Colors */

#define VT_BLACK	CSI+"30m"	/* Black                             */
#define VT_RED		CSI+"31m"	/* Red                               */
#define VT_GREEN	CSI+"32m"	/* Green                             */
#define VT_BROWN	CSI+"33m"	/* Brown or Yellow                   */
#define VT_YELLOW	CSI+"33m"	/* Yellow or Brown                   */
#define VT_BLUE		CSI+"34m"	/* Blue                              */
#define VT_MAGENTA	CSI+"35m"	/* Magenta                           */
#define VT_CYAN		CSI+"36m"	/* Cyan                              */
#define VT_WHITE	CSI+"37m"	/* White                             */

/* Background Colors */

#define VT_B_BLACK	CSI+"40m"	/* Black                             */
#define VT_B_RED	CSI+"41m"	/* Red                               */
#define VT_B_GREEN	CSI+"42m"	/* Green                             */
#define VT_B_BROWN	CSI+"43m"	/* Brown or Yellow                   */
#define VT_B_YELLOW	CSI+"43m"	/* Yellow or Brown                   */
#define VT_B_BLUE	CSI+"44m"	/* Blue                              */
#define VT_B_MAGENTA	CSI+"45m"	/* Magenta                           */
#define VT_B_CYAN	CSI+"46m"	/* Cyan                              */
#define VT_B_WHITE	CSI+"47m"	/* White                             */

#define RESET           CSI+"2;37;0m"   // reset terminal
#define VT_RESET        CSI+"2;37;0m"   // reset terminal

#define VT_NORMAL       VT_WHITE+VT_B_BLACK+VT_TA_AO

#endif // __VT_100_H__

