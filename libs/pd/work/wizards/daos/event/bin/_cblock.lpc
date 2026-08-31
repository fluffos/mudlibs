//  _classblock.c Created by Hanse@Nightmare and Screwit 3/5/93
//  It allows a wizard to tune in or out all the class lines with one command
//  Added sub class lines 

#include <daemons.h>
#include <std.h>

inherit DAEMON;

void help();

int cmd_cblock(string str) {
    string *list;
    int i;
    object tp;

    if(!str || (str != "on" && str != "off") ) {
	help();
	return 1;
    }
    tp=this_player();
    list = ({"fighter", "rogue", "clergy", "mage", "kataan", "wanderer",
      "cleric", "druid", "kataan", "monk","black", "blue", "red", 
      "white", "antipaladin", "berserker", "paladin", "ranger", "warrior", 
      "necromancer","pyromancer", "sorceror", "wizard", "rogue", "assassin", 
      "scout", "thief", "thug", "bard", "gypsy", "swasbuckler", "jester",
      "demon", "angel"});
    for(i=0;i<34;i++)
	if(str == "off" && tp->query_blocked(list[i]) )
	    tp->set_blocked(list[i]);
	else if(str == "on" && !tp->query_blocked(list[i]) )
	    tp->set_blocked(list[i]);
    write("Classblock: "+str+"\n");
    return 1;
}

void help() {
    write(@END
Syntax: <cblock (on/off)>

This command turns on all class lines or sub class lines or off all class lines and sub class lines.
END
    );
}
