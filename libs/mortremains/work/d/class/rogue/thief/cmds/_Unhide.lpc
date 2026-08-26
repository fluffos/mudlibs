//_Unhide.c will allow a thief to step out of the shadows at will.
//Nightmask@Nightfall's Keep Thurs. june 12th, 1997
#include <mudlib.h>

inherit DAEMON;

#define TPN this_player()->query("cap_name")

int cmd_Unhide() {
   object ob, invis_ob;
   int invis;
   ob = this_player();
   invis = (int)ob->query("invisible");
   if (invis) {
   	invis_ob = (present("#HIDE_OB#", ob));
   		if(invis_ob) invis_ob->remove();
     say (TPN+" steps out of the shadows.\n");
     write ("You step out of the shadows.\n");
    ob ->set("invisible", 0);
   } else {
      write("You are not currently hidden.\n");
   }
  return 1;
}
