 
//  File    :  /include/ansi.h
//  Creator :  Gothic@TMI-2  
//
//  The standard set of ANSI codes for mudlib use.
 
#define ESC ""
#define CSI ESC + "["

                /*  Foreground Colors  */
 
#define BLK ESC+"[30m"
#define RED ESC+"[31m"
#define GRN ESC+"[32m"
#define YEL ESC+"[33m"
#define BLU ESC+"[34m"
#define MAG ESC+"[35m"
#define CYN ESC+"[36m"
#define WHT ESC+"[37m"
 
                /*   Hi Intensity Foreground Colors   */
 
#define HIR ESC+"[1;31m"
#define HIG ESC+"[1;32m"
#define HIY ESC+"[1;33m"
#define HIB ESC+"[1;34m"
#define HIM ESC+"[1;35m"
#define HIC ESC+"[1;36m"
#define HIW ESC+"[1;37m"
#define HBK ESC+"[1;30m"
                /* High Intensity Background Colors  */
#define HBRED ESC+"[41;1m"
#define HBGRN ESC+"[42;1m"
#define HBYEL ESC+"[43;1m"
#define HBBLU ESC+"[44;1m"
#define HBMAG ESC+"[45;1m"
#define HBCYN ESC+"[46;1m"
#define HBWHT ESC+"[47;1m"
 
                /*  Background Colors  */
 
#define BBLK ESC+"[40m"
#define BRED ESC+"[41m"
#define BGRN ESC+"[42m"
#define BYEL ESC+"[43m"
#define BBLU ESC+"[44m"
#define BMAG ESC+"[45m"
#define BCYN ESC+"[46m"
// #define BWHT ESC+"[47m"          /* White    */
#define NOR ESC+"[2;37;0m"
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#define BOLD ESC+"[1m"
#define CLR ESC+"[2J"
#define HOME ESC+"[H"
#define REF CLR+HOME
#define BIGTOP ESC+"#3"
#define BIGBOT ESC+"#4"
#define SAVEC ESC+"[s"
#define REST ESC+"[u"
//#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#define SINGW ESC+"#5"
#define DBL ESC+"#6"
#define FRTOP ESC+"[2;25r"
#define FRBOT ESC+"[1;24r"
#define UNFR ESC+"[r"
#define BLINK ESC+"[5m"
#define U ESC+"[4m"
#define REV ESC+"[7m"
#define HIREV ESC+"[1,7m"
#define SETDISPLAY(x,y)  (ESC+"["+x+";"+y+"f")
#define DELLINE ESC+"[K"
#define FRELINE(x,y)  (ESC+"["+x+";"+y+"r")
#define TOBOT(x)  (ESC+"["+x+"B")
#define BEEP ""
