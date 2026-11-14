// Tamedhon MUDlib
//
// sys/www.h -- World Wide Web Services
//
// $Date: 2006/08/13 08:00:00 $
/* $Revision: 1.4 $
 * $Log: www.h,v $
 * Revision 1.4  2006/08/13 08:00:00  Querolin
 * diverse Neuerungen 
 *
 * Revision 1.3  1997/11/05 16:34:28  Woody
 * P_WWWINFO unabhaengig vom Mud definieren
 *
 * Revision 1.2  1997/07/01 16:11:46  Woody
 * PAGEHEAD/TAIL voruebergehend auf "" gesetzt
 *
 * Revision 1.1  1997/03/31 14:11:07  Woody
 * prepared for revision control
 *
 */

// how do you spell your mud name
#ifndef MUDNAME
#define MUDNAME    "Tamedhon"
#endif

// Pathnames to different services
// INETD -- the inet daemon
#ifndef INETD
#define INETD      "/secure/inetd"
#endif

#include "daemon.h"

#define FINGER(n)  FINGERMASTERWWW->finger_single(n)
// #define WHO        "/obj/werliste"->QueryWhoListe(0,0,1)
#define WHO        "/obj/werliste"->QueryWhoListe(0,0,2)

// UDPPATH -- wherethe udp programs are
#define UDPPATH    "/secure/udp"

// the WWW request scheduler
#define WWW   		(UDPPATH+"/www")
#define TIMEOUT		5

// wher to log all WWW UDP Requests
#define WWWLOG          "/WWW"  // used in log_file()

// define MUDHOST, WWW SERVER address and the ICON URL
#ifndef MUDHOST
#define MUDHOST         "mud.tamedhon.de"
#else
#undef MUDHOST
#define MUDHOST         "mud.tamedhon.de"
#endif
#define MUDUSER		"mud"
#define SERVER          "mud.tamedhon.de"
#define WEBSERVER	"www.tamedhon.de"
#define ICONS		"/icons_mud"
#define MUDWWW		"/cgi-bin/mudwww"
#define MUDWWWNEU	"/cgi-bin/mudwww"
#define WEBSTART	"www.tamedhon.de"

// define the address of the MUD Host
#define HOMEPAGE        "http://"+SERVER+"/"
#define MUDMAIL         "mailto:"+MUDUSER+"@"+MUDHOST

// some icons needed to navigate the pages
#define I_GO_BACK       ICONS+"/marble.left.gif"
#define I_GO_UP         ICONS+"/marble.up.gif"
#define I_GO_HOME       ICONS+"/marble.home.gif"
#define I_MAIL          ICONS+"/mail.gif"

// the text to prepend to any mudwww request answers
#define PAGEHEAD \
  "<HTML>" \
+ "<HEAD><TITLE>"+MUDNAME+"-WWW-Gast</TITLE></HEAD>" \
+ "<BODY>"

// append the following text to any mudwww request answer
// please do not remove the four lines before </BODY></HTML>
#define PAGETAIL \
  "<HR><H2><P ALIGN=\"CENTER\">" \
+ "<A HREF=\"telnet://"+MUDHOST+"/\">"+MUDNAME+" jetzt spielen!</A></H2>" \
+ "<HR><A HREF=\""+HOMEPAGE+"\"><IMG BORDER=0 SRC=\""+I_GO_HOME+"\" " \
+ "ALT=\"HOME\" ALIGN=\"RIGHT\"></A>" \
+ "<A HREF=\"#\"><IMG BORDER=0 SRC=\""+I_GO_UP+"\" " \
+ "ALT=\"Anfang\" ALIGN=\"RIGHT\"></A>" \
+ "<A HREF=\""+(back ? back : HOMEPAGE) + "\">" \
+ "<IMG BORDER=0 SRC=\""+I_GO_BACK+"\" ALT=\"Zurueck\" ALIGN=\"RIGHT\"></A>" \
+ "<ADDRESS>" \
+ "<IMG BORDER=0 SRC=\""+I_MAIL+"\" ALT=\"EMAIL\">" \
+ "<A HREF=\""+MUDMAIL+"\">"+MUDUSER+"@"+MUDHOST+"</A>" \
+ "</ADDRESS>" \
+ "<H6 ALIGN=\"CENTER\"><B><I>MudWWW[lp]</I></B> " \
+ "-- &copy; 1994,95 by " \
+ "<A HREF=\"mailto:hate@mg.uni-muenster.de\">Matthias L. Jugel</A> &amp; " \
+ "<A HREF=\"mailto:arachna@mg.uni-muenster.de\">Dirk Weigenand</A></H6>" \
+ "</BODY></HTML>"

#undef PAGEHEAD
#define PAGEHEAD ""

#undef PAGETAIL
#define PAGETAIL ""

// Request Syntax tokens
#define REQ     "REQ"		// TYPE of REQuest

// The WWW Newsreader
# define R_NEWS     "news"		// - we would like to read news
#  define GROUP       "GROUP"	//   * which newsgroup  
#  define ARTICLE     "ARTICLE"	//   * which article

// The WWW MUD Walker
# define R_WALK     "walk"		// - or maybe walk around a bit
#  define ROOM        "ROOM"	//   * ROOM to enter
#  define DETAIL      "DETAIL"	//   * DETAIL to examine

// The WWW Finger Request
#define R_FINGER   "finger"	// - finger someone
#define USER       "USER"	//   * USER to retrieve info from
#define PWD        "PWD"        //   * Passwort fuer www.login
#define VEREIN     "VEREIN"     //   * Abfrage auf Verein in www.login
#define ISWIZ      "ISWIZ"      //   * Abfrage auf is Wizzard

// The WWW Wholist Request
# define R_WHO      "who"		// - get the wholist

// The WWW Intermud Gateway
# define R_INTERMUD "intermud"	// - intermud communication request
#  define IMUD        "IMUD"	//   * The MUD to request info from
#  define TYPE        "TYPE"	//   * The TYPE of Request
#  define IDATA       "DATA"	//   * extra DATA to aid request
#  define PAGE        "PAGE"	//   * Alphabetical pages of muds

#define BACK    "BACK"		// PAGE to go BACK to

#ifndef MUDNAME
#define MUDNAME "TestMUD"
#endif /* MUDNAME */

// Property specific defines
// #if (MUDNAME == "MorgenGrauen" || MUDNAME == "SilberLand")
#define P_WWWINFO	"wwwinfo"
// #endif

// The error message to view in any case
#define ERROR(str)	"<H1>Ein Fehler ist aufgetreten!</H1><HR>"+str

// debugging (change name to your own!)
#define DNAME	"woody"
#define DEBUG(str) if(find_player(DNAME)) \
                     tell_object(find_player(DNAME), sprintf("%O\n", str))
//#undef DEBUG						       

