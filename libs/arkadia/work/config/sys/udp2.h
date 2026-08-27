/*
  udp2.h

  Local command extensions to the intermud protocol

*/
#define UDP_RWHO_Q 	"rwho_q"
#define UDP_RWHO_A 	"rwho_a"

#define RWHO_NO_MORTALS

/*
 * Unless we are at the real Genesis, dont tell the MUDWHO server anything
 */
#ifdef Genesis
#define UDP_MUDWHO "lysator.liu.se"
#define UDP_MW_ANONYMOUS
#endif

#define UDP_SUPPORT_ARRAY ({ UDP_STARTUP, UDP_SHUTDOWN, UDP_PING_Q, \
			     UDP_PING_A, UDP_MUDLIST_Q, UDP_MUDLIST_A, \
			     UDP_WARNING, UDP_SUPPORTED_Q, UDP_SUPPORTED_A, \
			     UDP_RWHO_Q, UDP_RWHO_A, UDP_GWIZMSG, \
			     UDP_GTELL, UDP_GFINGER_Q, UDP_GFINGER_A })










