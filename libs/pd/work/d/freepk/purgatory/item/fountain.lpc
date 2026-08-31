#include <std.h>
#include <purgatory.h>
inherit OBJECT;

void create() {
 ::create();
   set_id(({ "fountain" }));
   set_name("fountain");
   set_long("%^BOLD%^%^BLUE%^Carved from a large slab of %^BOLD%^%^BLACK%^black marble%^ "
"%^BOLD%^%^BLUE%^this fountain produces an elegant waterfall that cascades from the "
"%^BOLD%^%^BLUE%^ceiling onto many different plateaus of stone. The base of the "
"%^BOLD%^%^BLUE%^fountain houses a very deep pool of water where many fish swim. "
"%^BOLD%^%^BLUE%^There is a plaque at the base of this fountain, maybe you can read it.");
   set_short("a fountain");
   set_weight(1);
   set("value", 0);
   set_prevent_get( "The fountain will not budge." );

}
int readPlaque(string what) {
   if (!what || what != "plaque") return 0;
   tell_room(environment(this_player()), this_player()->query_cap_name()+
        " reads over the plaque on the fountain.", ({ this_player()}));
   write("The obsidian plaque reads: ");
   write("Welcome to the Purgatory Castle. The first King "
         "ordered this fountain build to honor his "
         "grandfather and had his mage enchant it so that "
         "all who drink will be healed.");
   write("A warning has been hurredly carved in the stone:\n");
write(@ENDTEXT
Beware the undead.
ENDTEXT);
   return 1;
}
int goDrink(string str) {
   if (str != "fount" && str != "fountain" && str != "from fount" && str !=
"from fountain") {
      notify_fail("Drink from what?\n");
      return 0;
   }
   if (this_player()->query_disable())
   {
    write("You cannot drink that fast.");
    return 1;
   }
 this_player()->set_disable();
 this_player()->heal(20);
 write("The water refreshes you.");
 return 1;
}


void init() {
 ::init();
   add_action("readPlaque", "read");
   add_action("goDrink", "drink");
}
