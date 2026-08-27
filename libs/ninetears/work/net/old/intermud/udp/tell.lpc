#include <newudp.h>
#define TELL_DEMON "/net/daemon/chars/tell_demon"

#ifdef ZEBEDEE
inherit "/sys/format";
#endif


void udp_tell(mapping data) {
    object ob;

    if (data[RECIPIENT] && (ob = find_player(data[RECIPIENT])) &&
    interactive(ob) && !ob->query_invis()) {
/*      ob->event_person_tell(this_object(),
            data[SENDER]+"@"+data[NAME]+" tells you: ", data[DATA], "common");
*/
        ob = clone_object(TELL_DEMON);
        ob->setup_tell(data[SENDER], data[NAME],
                       lower_case(data[RECIPIENT]), data[DATA]);
	INETD->send_udp(data[NAME], ([
	    REQUEST: REPLY,
	    RECIPIENT: data[SENDER],
	    ID: data[ID],
	    DATA: sprintf("%-80=s", "You tell " +
	    capitalize(data[RECIPIENT]) + "@" + LOCAL_NAME + ": " +
	    data[DATA]) + "\n"
	]) );
    }
    else
	INETD->send_udp(data[NAME], ([
	    REQUEST: REPLY,
	    RECIPIENT: data[SENDER],
	    ID: data[ID],
	    DATA: sprintf("%-80=s", "Wheeeee@" + LOCAL_NAME +
	    ": No such player: " + capitalize(data[RECIPIENT])) + "\n"
	]) );
}
