/* 
 *      Creator :  Gothic@TMI-2  
 *      The standard set of ANSI codes for mudlib use.
 *      Edited by Vertebraker, added BEEP, HIK, HIBLK
 */

#ifndef __ANSI__
#define __ANSI__

#ifndef ESC
#include "esc.h"
#ifndef ESC
#define ESC esc
#endif
#define CSI     ESC + "["
#endif

#ifndef BEEP
#define BEEP ""
#endif
 
/* wocket codez */
#ifndef EEOL
#define EEOL ESC+"[0K"
#endif
#ifndef EAOL
#define EAOL ESC+"[2K"
#endif
#ifndef ESOL
#define ESOL ESC+"[1K" /*erase start of line*/
#endif
#ifndef USCORE
#define USCORE ESC+"[4m"
#endif
#ifndef FLASH
#define FLASH ESC+"[5m"
#endif
#ifndef REC
#define REC ESC+"[7m"
#endif
#ifndef HIDE
#define HIDE ESC+"[8m"
#endif
#ifndef BS
#define BS ESC+"[D"
#endif
#ifndef FS
#define FS ESC+"[C"
#endif
#ifndef DS
#define DS ESC+"[B"
#endif
#ifndef US
#define US ESC+"[A"
#endif
#ifndef CLS
#define CLS ESC+"[2J"
#endif

		/*  Foreground Colors  */

#ifndef BLK 
#define BLK ESC+"[30m"          /* Black    */
#endif
#ifndef RED
#define RED ESC+"[31m"          /* Red      */
#endif
#ifndef GRN
#define GRN ESC+"[32m"          /* Green    */
#endif
#ifndef YEL
#define YEL ESC+"[33m"          /* Yellow   */
#endif
#ifndef BLU
#define BLU ESC+"[34m"          /* Blue     */
#endif
#ifndef MAG
#define MAG ESC+"[35m"          /* Magenta  */
#endif
#ifndef CYN
#define CYN ESC+"[36m"          /* Cyan     */
#endif
#ifndef WHT
#define WHT ESC+"[37m"          /* White    */
#endif

		/*   Hi Intensity Foreground Colors   */
 
#ifndef HIBLK
#define HIBLK ESC + "[1;30m"    /* hmph     */
#endif
#ifndef HIK
#define HIK HIBLK
#endif
#ifndef GRY
#define GRY HIK
#endif
#ifndef HIR
#define HIR ESC+"[1;31m"        /* Red      */
#endif
#ifndef HIG
#define HIG ESC+"[1;32m"        /* Green    */
#endif
#ifndef HIY
#define HIY ESC+"[1;33m"        /* Yellow   */
#endif
#ifndef HIB
#define HIB ESC+"[1;34m"        /* Blue     */
#endif
#ifndef HIM
#define HIM ESC+"[1;35m"        /* Magenta  */
#endif
#ifndef HIC
#define HIC ESC+"[1;36m"        /* Cyan     */
#endif
#ifndef HIW
#define HIW ESC+"[1;37m"        /* White    */
#endif
 
		/*  Background Colors  */
 
#ifndef BBLK
#define BBLK ESC+"[40m"          /* Black    */
#endif
#ifndef BRED
#define BRED ESC+"[41m"          /* Red      */
#endif
#ifndef BGRN
#define BGRN ESC+"[42m"          /* Green    */
#endif
#ifndef BYEL
#define BYEL ESC+"[43m"          /* Yellow   */
#endif
#ifndef BBLU
#define BBLU ESC+"[44m"          /* Blue     */
#endif
#ifndef BMAG
#define BMAG ESC+"[45m"          /* Magenta  */
#endif
#ifndef BCYN
#define BCYN ESC+"[46m"          /* Cyan     */
#endif
#ifndef BWHT
#define BWHT ESC+"[47m"          /* White    */
#endif
 
		/* High Intensity Background Colors  */

#ifndef HBBLK 
#define HBBLK ESC+"[40;1m"       /* Black, bleh */
#endif
#ifndef HBRED
#define HBRED ESC+"[41;1m"       /* Red      */
#endif
#ifndef HBGRN
#define HBGRN ESC+"[42;1m"       /* Green    */
#endif
#ifndef HBYEL
#define HBYEL ESC+"[43;1m"       /* Yellow   */
#endif
#ifndef HBBLU
#define HBBLU ESC+"[44;1m"       /* Blue     */
#endif
#ifndef HBMAG
#define HBMAG ESC+"[45;1m"       /* Magenta  */
#endif
#ifndef HBCYN
#define HBCYN ESC+"[46;1m"       /* Cyan     */
#endif
#ifndef HBWHT
#define HBWHT ESC+"[47;1m"       /* White    */
#endif
 
#ifndef NORM
#define NORM ESC + "[0m"
#endif
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#ifndef BOLD
#define BOLD ESC+"[1m"          /* Turn on bold mode */
#endif
#ifndef CLR
#define CLR ESC+"[2J"           /* Clear the screen  */
#endif
#ifndef HOME
#define HOME ESC+"[H"           /* Send cursor to home position */
#endif
#ifndef REF
#define REF CLR+HOME            /* Clear screen and home cursor */
#endif

#ifndef BIGTOP
#define BIGTOP ESC+"#3"         /* Dbl height characters, top half */
#endif
#ifndef BIGBOT
#define BIGBOT ESC+"#4"         /* Dbl height characters, bottem half */
#endif
#ifndef SAVEC
#define SAVEC ESC+"[s"          /* Save cursor position */
#endif
#ifndef REST
#define REST ESC+"[u"           /* Restore cursor to saved position */
#endif
#ifndef REVINDEX
#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#endif
#ifndef SINGW
#define SINGW ESC+"#5"          /* Normal, single-width characters */
#endif
#ifndef DBL
#define DBL ESC+"#6"            /* Creates double-width characters */
#endif
#ifndef FRTOP
#define FRTOP ESC+"[2;25r"      /* Freeze top line */
#endif
#ifndef FRBOT
#define FRBOT ESC+"[1;24r"      /* Freeze bottom line */
#endif
#ifndef UNFR
#define UNFR ESC+"[r"           /* Unfreeze top and bottom lines */
#endif
#ifndef BLINK
#define BLINK ESC+"[5m"         /* Initialize blink mode */
#endif
#ifndef U
#define U ESC+"[4m"             /* Initialize underscore mode */
#endif
#ifndef REV
#define REV ESC+"[7m"           /* Turns reverse video mode on */
#endif
#ifndef HIREV
#define HIREV ESC+"[1,7m"       /* Hi intensity reverse video  */
#endif

/* Codes from Grimm for compatibility --Vital */

#ifndef BLACK
#define BLACK BLK
#endif
#ifndef WHITE
#define WHITE WHT
#endif
#ifndef REVERSE
#define REVERSE REV
#endif
#ifndef GREEN
#define GREEN GRN
#endif

#ifndef BROWN
#define BROWN YEL
#endif
#ifndef YELLOW
#define YELLOW HIY
#endif
#ifndef BLUE
#define BLUE BLU
#endif
#ifndef MAGENTA
#define MAGENTA MAG
#endif
#ifndef CYAN
#define CYAN CYN
#endif
#ifndef END
#define END NORM
#endif
#ifndef REV_RED
#define REV_RED BRED
#endif
#ifndef REV_GREEN
#define REV_GREEN BGRN
#endif
#ifndef REV_BROWN
#define REV_BROWN BYEL
#endif
#ifndef REV_BLUE
#define REV_BLUE BBLU
#endif
#ifndef REV_MAGENTA
#define REV_MAGENTA BMAG
#endif
#ifndef REV_CYAN
#define REV_CYAN BCYN
#endif
#ifndef OFF
#define OFF NORM
#endif

#endif
