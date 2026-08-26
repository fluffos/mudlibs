// The keep command.
// (??-??-96) Written by Chronos.
#include <mudlib.h>

inherit DAEMON;

int cmd_keep(string str) {
    object *obs;
    object ob;
    int i;
    if (!str) {
	write("Keep what?\n");
	return 1;
    }
    if (str == "all") {
	obs=all_inventory(TP);
	if (!obs) {
	    write("You don't have anything to keep.\n");
	    return 1;
	}
	for(i=0;i<sizeof(obs);i++) {
	    if (obs[i]->query("short")) 
		write("You are keeping "+obs[i]->query("short")+".\n");
	    obs[i]->set("keep", 1);
	}
	return 1;
    }
    ob = present(str, TP);
    if (!ob) {
	write("Can't find that object.\n");
	return 1;
    }
    write("You are keeping "+ob->query("short")+ ".\n");
    ob->set("keep", 1);
    return 1;
}

string help() {
   return @ENDHELP
Usage: keep <item | all>

You can keep items to make the be excluded from such commands as 
"get all", "drop all", "sell all".  You won't accidentally get rid
of equipment if you keep it.

You must unkeep things before you can get rid of them.

Oh yeah.  "Kept" items are shown in your inventory with a * preceding
them.

See also: unkeep, drop, give, put
ENDHELP
  ;
}
