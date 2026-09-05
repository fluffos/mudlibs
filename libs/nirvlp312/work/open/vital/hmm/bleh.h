#include "/obj/security.h"
#include "/players/vital/closed/lib/lib.h"
#define VITAL "vital"


#define COMPAT
#define PROGRAM_NAME	program_name
#define IS_WIZARD(o)    (o->query_level>=20)

#define LIGHT		set_light(0)
#define SET_LIGHT	set_light
#define MOVE(x,y)	x->move_object(resolve_ob(y))
#define DESTRUCT(ob)	destruct(ob)

#define C(x)		capitalize(x)
#define L(x)		lower_case(x)
#define CAP(x)     capitalize(x)
#define LOW(x)     lower_case(x)
#define ME		this_object()
#define MEMBER(x,arr)	(member_array(x,arr)>=0)
#define MUDHOST		query_host_name()
#define PL		this_player()
#define OUT(str)	write(str+"\n")
#define FOREACH(arr,x)	for(x=0;x<sizeof(arr);x++)
#define FORALL(x, y) for(x=first_inventory(y);x;x=next_inventory(x))
#define FILTER(set)	if (!str)return 0;if(!MEMBER(L(str),(explode(set,"#"))))return 0
#define NOTIFY(mes)	{OUT(mes);return 1;}
#define FAIL(mes)	notify_fail(mes+"\n"); return 0
#define GETENV(x)	x=environment(ME);if(!x)return
#define OWNER(ob)	L(environment(ob)->query_real_name())
#define H_BANNER	1
#define H_CENTER	2
#define HEADLINE(x)	write (headline(x,0));
#define CENTER(x)	write (headline(x,H_CENTER));
#define BANNER(x)	write (headline(x,H_CENTER|H_BANNER));
#define TP          this_player()
#define QN          query_name()
#define TPN         TP->QN
#define CTPN        CAP(TPN)
#define TPP         this_player()->query_possessive()
#define LVL         TP->query_level()
#define TO          this_object()
#define CO(x)       clone_object(x)
#define LO(x)       load_object(x)
#define MO(x,y)     x->move_object(resolve_ob(y))
#define MP(x)       move_player(x)
#define FP(x)       find_player("x")
#define FO(x)       find_object(x)
#define ENV         environment
#define QRN         query_real_name()


#define NULL			0
#define INTEGER			1
#define STRING			2
#define OBJECT			3
#define ARRAY			4
#define SLOT			5
#define INDEX			6
#define ASTERISK		7
#define MAPPING			8
#define RESULT			9
#define CLOSURE			10
#define SYMBOL			11
#define FLOAT			12
#define DELAY			13
#define S_ARRAY			14
#define S_MAPPING		15
#define S_CLOSURE		16
#define S_SYMBOL		17
#define S_FLOAT			18
#define S_STRING		19
#define S_OBJECT		20
#define S_EFUN			21
#define SUBCALL			22
#define MULTIARG		23

#define INDEXTYPE_UNKNOWN	"unknown"
#define INDEX_PLAIN		"plain"
#define INDEX_INTERVAL		"interval"
#define INDEX_RIGHTBORDER	"rightborder"
#define INDEX_RBORDER		"rborder"
#define INDEX_LEFT		"left"
#define INDEX_RIGHT		"right"

#define ESC     ""
#define CSI     ESC + "["
 
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
 
		/*  Background Colors  */
 
#define BBLK ESC+"[40m"          /* Black    */
#define BRED ESC+"[41m"          /* Red      */
#define BGRN ESC+"[42m"          /* Green    */
#define BYEL ESC+"[43m"          /* Yellow   */
#define BBLU ESC+"[44m"          /* Blue     */
#define BMAG ESC+"[45m"          /* Magenta  */
#define BCYN ESC+"[46m"          /* Cyan     */
#define BWHT ESC+"[47m"          /* White    */
 
		/* High Intensity Background Colors  */
 
#define HBRED ESC+"[41;1m"       /* Red      */
#define HBGRN ESC+"[42;1m"       /* Green    */
#define HBYEL ESC+"[43;1m"       /* Yellow   */
#define HBBLU ESC+"[44;1m"       /* Blue     */
#define HBMAG ESC+"[45;1m"       /* Magenta  */
#define HBCYN ESC+"[46;1m"       /* Cyan     */
#define HBWHT ESC+"[47;1m"       /* White    */
 
#define NORM ESC+"[2;37;0m"      /* Puts everything back to normal */
 
/*  Additional ansi Esc codes added to ansi.h by Gothic  april 23,1993 */
/* Note, these are Esc codes for VT100 terminals, and emmulators */
/*       and they may not all work within the mud               */
 
#define BOLD ESC+"[1m"          /* Turn on bold mode */
#define CLR ESC+"[2J"           /* Clear the screen  */
#define HOME ESC+"[H"           /* Send cursor to home position */
#define REF CLR+HOME            /* Clear screen and home cursor */
#define BIGTOP ESC+"#3"         /* Dbl height characters, top half */
#define BIGBOT ESC+"#4"         /* Dbl height characters, bottem half */
#define SAVEC ESC+"[s"          /* Save cursor position */
#define REST ESC+"[u"           /* Restore cursor to saved position */
#define REVINDEX ESC+"M"        /* Scroll screen in opposite direction */
#define SINGW ESC+"#5"          /* Normal, single-width characters */
#define DBL ESC+"#6"            /* Creates double-width characters */
#define FRTOP ESC+"[2;25r"      /* Freeze top line */
#define FRBOT ESC+"[1;24r"      /* Freeze bottom line */
#define UNFR ESC+"[r"           /* Unfreeze top and bottom lines */
#define BLINK ESC+"[5m"         /* Initialize blink mode */
#define U ESC+"[4m"             /* Initialize underscore mode */
#define REV ESC+"[7m"           /* Turns reverse video mode on */
#define HIREV ESC+"[1,7m"       /* Hi intensity reverse video  */
 


object armor, ring, helmet, misc, amulet, boots, shield;
object coins;
object human;
string str;
int x, y, z;