#define tp this_player()->query_name()
#include "/players/puppy/define.h"
inherit "obj/treasure";

reset(arg)  {
   if(arg) return;
   
   set_id("whistle");
   set_short("A large whistle");
   set_long(
      "A large whistle that you can 'blow'.\n");
   set_weight(0);
   set_value(5);
}

init()
{  add_action("blow_whistle", "blow");   }
blow_whistle(str)  {
   if(str == "whistle")  {
      
      write("You blow the whistle.\n SHHHHRRREEEEEEEEEEEEEEEEEEEEEEE\n");
      /* Note how tp is used */
      say(tp+" blows a whistle.\n SHHHHRRREEEEEEEEEEEEEEEEEEEEEEEEEE\n");
      return 1;   }
   
}
