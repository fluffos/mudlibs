#include <rogues.h>
#include <mudlib.h>

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_makemyday(){
   object ob;
   string gun;
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }
   if (!TP->query("weapon1")) {
     write("You need a gun to do that.\n");
   return 1;
 } else {
  }
   gun = this_player()->query("weapon1");

   say(TPN+" waves "+POSS+" "+gun->query("short")+" around"
     +" and says, \"Go ahead, make my day.\"\n");
   write("You wave your "+gun->query("short")+" around"
     +" and say, \"Go ahead, make my day.\"\n");
   return 1;
    }
