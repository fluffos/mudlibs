// - syphon -

#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_id(({"well"}));
   set_name("well");
   set_short("%^BOLD%^%^BLUE%^an old well%^RESET%^");
    set_long("The old well has stood in the Tirun "
            "square for ages. It has been said to give those "
            "who drink from it good luck and to heal the hurt.");

   set_prevent_get( "You cant pull the well out from underground." );
}



int init()
{
 ::init();
   add_action("goDrink", "drink");
}

int goDrink(string str) {
   if (str != "well" && str != "from well") {
      notify_fail("Drink from what?\n");
      return 0;
   }
   if (this_player()->query_disable())
   {
    write("You cannot drink that fast.");
    return 1;
   }
 this_player()->set_disable();
/* this_player()->add_mp(20);
 this_player()->add_sp(10);
 this_player()->add_hp(10);
*/
  this_player()->heal(10);
 write("%^BOLD%^%^BLUE%^The well water refreshes you.%^RESET%^");
 return 1;
}
