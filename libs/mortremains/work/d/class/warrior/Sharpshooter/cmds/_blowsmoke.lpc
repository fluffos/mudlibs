#include <rogues.h>
#include <mudlib.h>
#include "camel.h"

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_blowsmoke(){
  object ob;
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }
   write("You raise your gun to your lips and blow the smoke off the barrel.\n");
   say(TPN+" raises "+POSS+" gun to "+POSS+" lips and blows the"
      +" smoke off the barrel.\n");
    return 1;
}
