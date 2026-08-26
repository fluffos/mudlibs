#include <rogues.h>
#include <mudlib.h>

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_brandish(){
   object ob;
   string gun;
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }
   if (!TP->query("weapon1")) {
     write("You need a weapon to do that.\n");
   return 1;
  }
   gun = this_player()->query("weapon1");

   say(TPN+" brandishes "+POSS+" "+gun->query("short")+" for"
     +" all to see.\n");
   write("You brandish your "+gun->query("short")+" for all to see.\n");
   return 1;
    }
