//_Unhide.c will allow a thief to step out of the shadows at will.
//Nightmask@Nightfall's Keep Thurs. june 12th, 1997
#include <mudlib.h>

inherit DAEMON;

#define TPN this_player()->query("cap_name")

object ob, invis_ob;
int invis;

int cmd_Appear() {
  if (TP->query_level() < 20) {
     write("You must be at least level 20 to do that.\n");
  return 1;
 }
   ob = this_player();
   invis = (int)ob->query("invisible");
    if(invis == 1) {
   	invis_ob = (present("#HIDE_OB#", ob));
   		if(invis_ob) invis_ob->remove();
     say("The shadows swirl and take the form of "+TPN+".\n");
     write("You ememgre from the shadows.\n");
    ob ->set("invisible", 0);
   } else {
      write("You are not currently hidden.\n");
   }
  return 1;
}
