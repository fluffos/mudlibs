#include <rogues.h>
#include <mudlib.h>
#include "camel.h"

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_guntwirl(){
    object ob;
    string gun;
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }
    gun = this_player()->query("weapon1");
    if(!gun){
	write("You must first wield your weapon.\n");
	return 1;
    }
    write("You twirl your "+gun->query("short")+
      " with style.\n");
   say(wrap(TPN+" twirls "+POSS+" "+
	gun->query("short")+" around. You marvel at "+POSS+" skill."));
    return 1;
}
