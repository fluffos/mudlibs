#include <daemons.h>
#include <std.h>

inherit DAEMON;

void help();

int cmd_lblock(string str) {
    string *list;
    int i;
    object tp;

    if(!str || (str != "on" && str != "off") ) {
	help();
	return 1;
    }

    tp=this_player();
    list= ({"newbie", "hm", "elite", "legend", "gossip", "OOC", "trivia", 
      "guild", "legend", "colosseum", "auction"});
    for(i=0;i<11;i++)
	if(str == "off" && tp->query_blocked(list[i]) )
	    tp->set_blocked(list[i]);
	else if(str == "on" && !tp->query_blocked(list[i]) )
	    tp->set_blocked(list[i]);
    write("Lineblock: "+str+"\n");
    return 1;
}

void help() {
    write(@END
Syntax: <lblock (on/off)>

This command turns on all open lines and off open lines.
END
    );
}
