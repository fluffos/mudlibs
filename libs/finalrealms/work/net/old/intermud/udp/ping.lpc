#include <newudp.h>

void udp_ping(mapping data) {
    INETD->send_udp(data[NAME], ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	DATA: LOCAL_NAME + " is alive.\n"
    ]) );
}
