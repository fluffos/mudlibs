//      /adm/daemons/network/dns_aux/locate_a.c
//      from the TMI-2 Mudlib
//      the locate_a for the UDP locate function
//      created by Descartes of Borg 931017

#include <net/config.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

void incoming_request(mapping info) {
    object who;

    if(!info["NAME"] || !info["PORTUDP"]) return;
    if(!info["ASKWIZ"] || !(who = find_player(lower_case(info["ASKWIZ"]))))
      return;
    switch(info["LOCATE"]) {
        case "NO": return;
        case "YES":
          message("info", sprintf("LOCATE:  %s was just located on %s.\n", 
            capitalize(info["TARGET"]), nntoh(info["NAME"])), who);
          break;
        default: /* log bad answers here if you like */
    }
    return;
}

int encoding(string arg) {
	string IP;
	int isBig5,i;
	IP = arg[0..2];
	isBig5 = 0;
	for(i=0;i<sizeof(Big5IP);i++){
		if( IP == Big5IP[i] ) isBig5 = 1;
	}
	return isBig5;
}