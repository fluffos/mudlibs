#include <network.h>
void do_finger(string str) {
    string name, host, realhost;

    if (sscanf(str, "%s@%s", name, host) == 2) {
	if ((realhost = INTERMUD_D->GetMudName(replace_string(host, ".", " ")))) {
	    if (name == "")
		SERVICES_D->eventSendWhoRequest(realhost, this_player()->query_name());
	    else
		SERVICES_D->eventSendFingerRequest(name, realhost);
	    write("Intermud3 finger on it's way.\n");
	    return;
	}
	write(mud_name()+" does not know about the MUD "+host+".\n");
	return;
    }
} /* do_finger() */
