// Dragon cast is the same as mage's cast.

#include <config.h>

string *allowed = ({
"/d/class/dragon/rooms/dragon_guild",
START
});

int cmd_fly (string str) { 
    object here = environment(TP);
    int i;

    if (!here) {
	write("You cannot fly from the void!\n");
	return 1;
    }

    str = base_name(here);
    i = member_array(str, allowed);

    if (i==-1) {
	write(wrap("You may only fly from the start location, or "+
	    "the Dragon's Lair."));
	return 1;
    }

    // Neat, eh?
    str = allowed[!i];

    say(TPN+" leaps into the air and flies off.\n");
    write("You leap into the air, and fly off.\n");
    TP->move_player(str, "SNEAK");
    say(TPN+" flies above you, and sets down nearby.\n");

    return 1;
}

/* EOF */
