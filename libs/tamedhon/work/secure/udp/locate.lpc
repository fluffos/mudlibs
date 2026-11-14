/* SilberLand MUDlib
 *
 * /secure/udp/locate.c -- UDP locator
 *
 * $Date: 1997/03/16 00:10:33 $
 * $Revision: 1.1 $
 * $Log: locate.c,v $
 * Revision 1.1  1997/03/16 00:10:33  Woody
 * prepared for revision control
 *
 */

#include <udp.h>

#define FOUND		"fnd"
#define USER		"user"
#define VERBOSE		"vbs"

void udp_locate(mapping data) {
    mapping ret;
    object ob;

    ret = ([
	REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
	USER: data[USER],
	VERBOSE: data[VERBOSE],
    ]);
    if (data[DATA] && (ob = find_player(data[DATA])) &&
    interactive(ob) && !ob->query_invis()) {
	ret[FOUND] = 1;
	ret[DATA] = "locate@" + LOCAL_NAME + ": " + ob->short();
    }
    else
	ret[DATA] = "locate@" + LOCAL_NAME + ": No such player: " +
	data[DATA] + "\n";
    INETD->send_udp(data[NAME], ret);
}
