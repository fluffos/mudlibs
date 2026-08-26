#include <net/i3.h>

int cmd_tap(string args){
    if(!args){
	write("Syntax: tap <level>\n");
	return 1;
    }
    if(!adminp(this_player())) return 0;
    I3_DAEMON->set_debugging(to_int(args), this_player());
    write("DNS tapped at level "+args+"\n");
    return 1;
}
