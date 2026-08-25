#include <newudp.h>

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
#ifdef CDLIB
	ret[DATA] = "locate@" + LOCAL_NAME + ": "+ ob->query_presentation()
		+"\n";
#else
	ret[DATA] = "locate@" + LOCAL_NAME + ": " + ob->short() + "\n";
#endif
    }
    else
	ret[DATA] = "locate@" + LOCAL_NAME + ": No such player: " +
	data[DATA] + "\n";
    INETD->send_udp(data[NAME], ret);
}
