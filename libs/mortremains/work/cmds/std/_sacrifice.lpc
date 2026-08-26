// File: _bury.c
// Date: July 23rd, 1997.
// Purpose: To get rid of them smelly things known as corpses.
// Original Initative: Nightmask
// Fixed by Cyanide

#include <mudlib.h>
inherit DAEMON;

int cmd_sacrifice(string str){
    object corpse;
    string deity;

    if (!str) {
	write("Sacrifice what?\n");
	return 1;
    }
    corpse = present("dead body", environment(TP));
    if (str == "corpse" && (corpse)) {
	deity = TP->query("deity");
     if (!deity) deity = "the gods" ;
	write("You call upon "+deity+" to guide this spirit to the afterlife.\n");
	say(TPN+" sacrifices a corpse to "+deity+".\n");
	if (TP->query("max_tp")){
	    TP->add("theurgy_points", corpse->query("level") * 2); 
	    if (TP->query("theurgy_points") > TP->query("max_tp")){
		TP->set("theurgy_points", TP->query("max_tp"));
	    }
	}
	corpse->remove();
	return 1;
    }
    return 0;
}
