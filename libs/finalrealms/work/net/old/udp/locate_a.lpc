#include <udp.h>
/*
 * locate_q, handles incoming replies to our locate requests.
 * Modified to be used with the DW lib by Turrican@Discworld.
 * 30-1-95
 */

void incoming_request(mapping info) {
    object who;
 
    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!info["ASKWIZ"] || !(who = find_player(lower_case(info["ASKWIZ"]))))
      return;
    switch(info["LOCATE"]) {
        case "NO": return;
        case "YES":
          tell_object(who, "LOCATE:  "+info["TARGET"]+" was just "+
            "located on "+info["NAME"]+".\n"); 
          break;
        default: /* log bad answers here if you like */
    }
    return;
}
