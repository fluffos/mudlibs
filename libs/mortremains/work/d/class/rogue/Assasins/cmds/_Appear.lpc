//_Unhide.c will allow a thief to step out of the shadows at will.
//Nightmask@Nightfall's Keep Thurs. june 12th, 1997
#include <mudlib.h>

inherit DAEMON;

#define TPN this_player()->query("cap_name")

object ob;
int invis;

int cmd_Appear() {
   ob = this_player();
   invis = (int)ob->query("invisible");
    if(invis == 1) {
     say("The shadows swirl and take the form of "+TPN+".\n");
     write("You ememgre from the shadows.\n");
    ob ->set("invisible", 0);
   } else {
      write("You are not currently hidden.\n");
   }
  return 1;
}
