#include <newudp.h>

void udp_finger(mapping data) {
    string finger, *bits;
    int i;
    object ob;

    finger = "/secure/finger"->finger_info(lower_case(data[DATA]));
    if (!finger)
      finger = "I am most dreadfully sorry, but "+data[DATA]+
               " has not visited here yet.  Try again later :)\n";
    else {
      ob = clone_object("/net/daemon/chars/in_finger_demon");
      ob->setup_finger(lower_case(data[DATA]));
    }
    INETD->send_udp(data[NAME], ([
        REQUEST: REPLY,
	RECIPIENT: data[SENDER],
	ID: data[ID],
        DATA: finger,
    ]) );
} /* udp_finger() */
