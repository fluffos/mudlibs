// Scan : an ability for Sharpshooters, level 5
// It allows the player to get a general idea of their
// Targets armour class.
// Brought to you by Nightmask.

#include <mudlib.h>
#include "checkob.h"

inherit DAEMON;


#define SS "/d/class/warrior/Sharpshooter/"

int cmd_scan(string str) {
    int ac;
    object targ;

    if (!checkob(TP)) return 1;

    if (!str) {
	write("You must scan somthing.\n");
	return 1;
    }

    targ = present(str, environment(this_player()));

    if (!targ) {
	write("Yuo see nothing like that through your eyelink.\n");
	return 1;
    }
   if (TP->query_level() < 5) {
	write("Your eyelink is not yet equipped to do that.\n");
	return 1;
    }
    if(!this_player()->query("vision")) {
	write("It's too dark for that.\n");
	return 1;
    }
    ac = targ->query("armor_class");
    switch(ac){
   case 10..7 : write("Just clothing, and easy mark.\n");break;
   case 6..4 : write("Almost naked, stray bullets would hit.\n");break;
   case 3..1 : write("Armoured, you might need to be percise.\n");break;
   case 0..-2 : write("Slightly armoured, percise shots will hit.\n");break;
   case -3..-6 : write("Moderatly armoured, you need to be exact.\n");break;
   case -7..-10 : write("Heavily armoured, some shots may bounce off.\n");break;
   default : write("Unreal armour, might want to back off.\n");break;
 }
 return 1;
}
