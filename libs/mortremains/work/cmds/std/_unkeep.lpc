// The unkeep command.
// (09-12-96) Written by Chronos.
#include <mudlib.h>

inherit DAEMON;

int cmd_unkeep(string str) {
    object *obs;
    object ob;
    int i, silent;
    if (!str) {
	write("Unkeep what?\n");
	return 1;
    }
    if (str == "all -silent") {
	str = "all";
	silent = 1;
    }
    if (str == "all") {
	obs=all_inventory(TP);
	if (!obs) {
	    if (!silent)
		write("You don't have anything.\n");
	    return 1;
	}
	for(i=0;i<sizeof(obs);i++) {
	    if (!silent && obs[i]->query("short")) 
		write("You are not keeping "+obs[i]->query("short")+".\n");
	    obs[i]->delete("keep");
	}
	return 1;
    }
    ob = present(str, TP);
    if (!ob) {
	if (!silent)
	    write("Can't find that object.\n");
	return 1;
    }
    if (!silent)
	write("You are not keeping "+ob->query("short")+ ".\n");
    ob->delete("keep");
    return 1;
}

string help() {
   return @ENDHELP
Usage: unkeep <item | all>

You can unkeep items to stop keeping them.

You must unkeep things before you get rid of them.

See also: keep, drop, put, give
ENDHELP
  ;
}
