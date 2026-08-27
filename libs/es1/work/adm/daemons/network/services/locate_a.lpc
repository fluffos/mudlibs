#include <mudlib.h>
#include <net/macros.h>

inherit DAEMON;

void incoming_request(mapping info) {
    object who;
 
    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!info["ASKWIZ"] || !(who = find_player(lower_case(info["ASKWIZ"]))))
      return;
    switch(info["LOCATE"]) {
        case "NO": return;
        case "YES":
          message("info", sprintf("LOCATE:  %s was just located on %s.\n", 
	capitalize( info["TARGET"] ), 
	DNS_MASTER -> query_alias( info["NAME"] )), who );
          break;
        default: /* log bad answers here if you like */
    }
    return;
}

