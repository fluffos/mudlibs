/*
  udp.h

  Some appropriate defines for the intermud protocol.

  The GD support for this is merely to supply the capability of sending
  and receiving arbitrary messages from arbitrary host:port

*/
#ifndef UDP_DEFINED
#define UDP_DEFINED

/*
 * UDP_ENABLED
 *
 * Define this in order to have any UDP functionality work. If not, then the
 * UDP code will be as dead as possible.
 */
#undef UDP_ENABLED

/*
 * UDP_NUM_NO_CONNECT
 *
 * Number of 30-minute periods before the mud is considered 'not known'
 */
#define UDP_NUM_NO_CONTACT 	25
#define UDP_NO_CONTACT 		"_no_contact"

/*
  All messages are on the format:
  
       @@@command||parameter||parameter||parameter||parameter@@@

  Below is the commands included as the basic protocol defined:
*/
#define UDP_STARTUP	"startup"
#define UDP_SHUTDOWN	"shutdown"

/* These are the standard udp extensions
 */
#define UDP_WARNING 	"warning"
#define UDP_PING_Q	"ping_q"
#define UDP_PING_A	"ping_a"
#define UDP_MUDLIST_Q	"mudlist_q"
#define UDP_MUDLIST_A	"mudlist_a"
#define UDP_SUPPORTED_Q	"supported_q"
#define UDP_SUPPORTED_A	"supported_a"
#define UDP_RWHO_Q 	"rwho_q"
#define UDP_RWHO_A 	"rwho_a"
#define	UDP_GTELL	"gtell"
#define	UDP_GWIZMSG	"gwizmsg"
#define	UDP_GFINGER_Q	"gfinger_q"
#define	UDP_GFINGER_A	"gfinger_a"

/*
 * UDP_MUDWHO
 *
 * If this is defined (as a host) then send MUDWHO information there.
 *
 * NOTE
 *   This server is not the same as the CDlib MUDLIST_SERVER. The MUDWHO
 *   server is something that registers muds of all forms and shapes.
 *   They serve two different purposes and can be used or not used
 *   independantly.
 */
#undef UDP_MUDWHO "lysator.liu.se"

/*
 * UDP_MW_ANONYMOUS
 *
 * If defined names of characters will not be sent to the mudwho server
 */
#undef UDP_MW_ANONYMOUS

/*
 * In the below file you can include all extra services you want at
 * your mud. Note that there is a standard for adding services and
 * that many such single extension files will be available through ftp
 * from alcazar.cd.chalmers.se::/pub/cdlib/udp_extensions
 */

/* At Genesis, we don't want to have anything to do with UDP. */
#undef UDP_ENABLED

#define UDP_RWHO_Q 	"rwho_q"
#define UDP_RWHO_A 	"rwho_a"

#define RWHO_NO_MORTALS

#define UDP_SUPPORT_ARRAY ({ UDP_STARTUP, UDP_SHUTDOWN, UDP_PING_Q, \
			     UDP_PING_A, UDP_MUDLIST_Q, UDP_MUDLIST_A, \
			     UDP_WARNING, UDP_SUPPORTED_Q, UDP_SUPPORTED_A, \
			     UDP_RWHO_Q, UDP_RWHO_A, UDP_GWIZMSG, \
			     UDP_GTELL, UDP_GFINGER_Q, UDP_GFINGER_A })

/*
 * You should define the below arrar in your udp2.h file so that
 * it includes your extensions
 */
#ifndef UDP_SUPPORT_ARRAY

#define UDP_SUPPORT_ARRAY ({ \
				UDP_STARTUP,	 	\
				UDP_SHUTDOWN,	 	\
				UDP_PING_Q,	 	\
				UDP_PING_A, 		\
				UDP_MUDLIST_Q, 		\
				UDP_MUDLIST_A, 		\
				UDP_WARNING, 		\
				UDP_SUPPORTED_Q, 	\
				UDP_SUPPORTED_A, 	\
				})

#endif

#ifdef UDP_MUDWHO

/* 
 * These defines are the syntax of the MUDWHO protocol as given by 
 * Marcus J. Ranum 1991.
 */
#define UDP_MW_PORT 		6888

#define UDP_MW_REPEAT_TIME 	(150.0)

#define UDP_MW_UP(name, pass, comment) 				\
	sprintf("U\t%.20s\t%.20s\t%.20s\t%.10d\t0\t%.25s",	\
		name, pass, name, time(), comment)

#define UDP_MW_DOWN(name, pass, comment) 			\
	sprintf("D\t%.20s\t%.20s\t%.20s",			\
		name, pass, name)

#define UDP_MW_LIVE(name, pass, comment) 			\
	sprintf("M\t%.20s\t%.20s\t%.20s\t%.10d\t0\t%.25s",	\
		name, pass, name, time(), comment)
		
#define UDP_MW_USER_IN(name, pass, uid, cname) 				\
	sprintf("A\t%.20s\t%.20s\t%.20s\t%.20s\t%.10d\t0\t%.20s",	\
		name, pass, name, uid, time(), cname)

#define UDP_MW_USER_OUT(name, pass, uid)			\
	sprintf("Z\t%.20s\t%.20s\t%.20s\t%.20s",		\
		name, pass, name, uid)

#endif /* UDP_MUDWHO */

/* No definitions beyond this line. */
#endif /* UDP_DEFINED */

