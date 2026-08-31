#include <daemons.h>
#include <std.h>

inherit DAEMON;

void help();

int cmd_gblock(string str) {
    string *list;
    int i;
    object tp;

    if(!str || (str != "on" && str != "off") ) {
	help();
	return 1;
    }

    tp=this_player();
    list= ({"darksoul","DW", "ethereal", "unholy", "scorpio", "vorticon",
      "forsaken", "illuminati", "chosen", "dw", "acheron"});
    for(i=0;i<11;i++)
	if(str == "off" && tp->query_blocked(list[i]) )
	    tp->set_blocked(list[i]);
	else if(str == "on" && !tp->query_blocked(list[i]) )
	    tp->set_blocked(list[i]);
    write("Guildblock: "+str+"\n");
    return 1;
}

void help() {
    write(@END
Syntax: <gblock (on/off)>

This command turns on all guild lines and off guild lines.
END
    );
}
