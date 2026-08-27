#include <newudp.h>

#define CHANNEL		"channel"
#define COMMAND         "cmd"

int filter_listeners(object ob, string channel) {
  if (!ob->query_creator() || ob->check_earmuffs("intermud-all") || 
      ob->check_earmuffs(channel))
    return 0;
  return 1;
} /* filter_listeners() */

void udp_channel(mapping data) {
    object *list;
    string msg, start;
    int i;

    /* Compatability with older systems. */
    if (!data[CHANNEL])
	data[CHANNEL] = data["CHANNEL"];
    if (!data[COMMAND])
	data[COMMAND] = data["CMD"];

    switch(data[COMMAND]) {
	case "emote":
	    start = capitalize(data[SENDER]) + "@" + capitalize(data[NAME]) +
                " ";
	    break;
	case "list":
	    list = filter_array(
	    users(), "filter_listeners", this_object(), data[CHANNEL]);
	    if (i = sizeof(list)) {
		msg = "[" + capitalize(data[CHANNEL]) + "@" +
		LOCAL_NAME + "] Listening:\n";
		while(i--)
		    msg +=
		    "    " + list[i]->query_cap_name() + "\n";
	    } else
		msg = "[" + capitalize(data[CHANNEL]) + "@" +
		LOCAL_NAME + "] Nobody Listening.\n";
	    INETD->send_udp(data[NAME], ([
	   		REQUEST: REPLY,
			RECIPIENT: data[SENDER],
			ID: data[ID],
			DATA: msg
	    	]) );
	    return;
	default:
	    start = capitalize(data[SENDER]) + "@" + capitalize(data[NAME])+
                ": ";
	    break;
    }
    if (lower_case(data[CHANNEL]) == "d-chat") return;
    event(users(), "intermud_tell", start, data[DATA], data[CHANNEL]);
    /* Never generate an error. Unknown channels can be ignored later. */
} /* udp_channel() */
