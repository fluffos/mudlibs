 
//	File	:  /include/ansi.h
//	Creator	:  Gothic@TMI-2  
//
//	The standard set of ANSI codes for mudlib use.
 
#define ESC	""
#define CSI	ESC + ""
                  /*  Qmud关键字设置  */
#define NPL	"♂"
#define NPB "ā"
#define NPA "[addm"
#define NPD "[delm"
#define DROP "[dropm"
                /*  Foreground Colors  */
 
#define BLK ESC+"[30m"          /* Black    */
#define RED ESC+"[31m"          /* Red      */
#define GRN ESC+"[32m"          /* Green    */
#define YEL ESC+"[33m"          /* Yellow   */
#define BLU ESC+"[34m"          /* Blue     */
#define MAG ESC+"[35m"          /* Magenta  */
#define CYN ESC+"[36m"          /* Cyan     */
#define WHT ESC+"[37m"          /* White    */
 
                /*   Hi Intensity Foreground Colors   */
 
#define HIR ESC+"[1;31m"        /* Red      */
#define HIG ESC+"[1;32m"        /* Green    */
#define HIY ESC+"[1;33m"        /* Yellow   */
#define HIB ESC+"[1;34m"        /* Blue     */
#define HIM ESC+"[1;35m"        /* Magenta  */
#define HIC ESC+"[1;36m"        /* Cyan     */
#define HIW ESC+"[1;37m"        /* White    */

                /* High Intensity Background Colors  */

#define HBRED ESC+""       /* Red      */
#define HBGRN ESC+""       /* Green    */
#define HBYEL ESC+""       /* Yellow   */
#define HBBLU ESC+""       /* Blue     */
#define HBMAG ESC+""       /* Magenta  */
#define HBCYN ESC+""       /* Cyan     */
#define HBWHT ESC+""       /* White    */
 
                /*  Background Colors  */
 
#define BBLK ESC+""          /* Black    */
#define BRED ESC+""          /* Red      */
#define BGRN ESC+""          /* Green    */
#define BYEL ESC+""          /* Yellow   */
#define BBLU ESC+""          /* Blue     */
#define BMAG ESC+""          /* Magenta  */
#define BCYN ESC+""          /* Cyan     */
// #define BWHT ESC+"[47m"          /* White    */

#define NOR ESC+"[2;37;0m"      /* Puts everything back to normal */
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#define BOLD ESC+""          /* Turn on bold mode */
#define CLR ESC+""           /* Clear the screen  */
#define HOME ESC+""           /* Send cursor to home position */
#define REF CLR+HOME            /* Clear screen and home cursor */
#define BIGTOP ESC+""         /* Dbl height characters, top half */
#define BIGBOT ESC+""         /* Dbl height characters, bottem half */
#define SAVEC ESC+""           /* Save cursor position */
#define REST ESC+""            /* Restore cursor to saved position */
//#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#define SINGW ESC+""          /* Normal, single-width characters */
#define DBL ESC+""            /* Creates double-width characters */
#define FRTOP ESC+""      /* Freeze top line */
#define FRBOT ESC+""      /* Freeze bottom line */
#define UNFR ESC+""           /* Unfreeze top and bottom lines */
#define BLINK ESC+""         /* Initialize blink mode */
#define U ESC+""             /* Initialize underscore mode */
#define REV ESC+""           /* Turns reverse video mode on */
#define HIREV ESC+""       /* Hi intensity reverse video  */
 
