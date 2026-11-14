/* SilberLand MUDlib
 *
 * /secure/udp/ping.c -- UDP ping handling
 *
 * $Date: 1997/03/16 00:13:04 $
 * $Revision: 1.1 $
 * $Log: ping.c,v $
 * Revision 1.1  1997/03/16 00:13:04  Woody
 * prepared for revision control
 *
 */

#include <udp.h>

#ifdef ZEBEDEE
#include <system.h>
#elif !defined(INETD)
#define INETD	"/secure/inetd"
#endif

void udp_ping(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: LOCAL_NAME + " is alive.\n"
    ]) );
}
