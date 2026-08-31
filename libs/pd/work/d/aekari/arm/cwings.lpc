
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("crystal wings");
   set_id( ({"wings","crystal wings"}) );
   set_short("%^BOLD%^%^CYAN%^Crystal WIngs%^RESET%^");
   set_long(
     "A robe made from a cotton fiber. It is not terribly ornate "
     "nor is it terribly strong. It looks to be well kept. "
   );
   set_ac(1);
   set_mass(8);
   set_curr_value("gold", 60);
   set_type("ring");
   set_limbs( ({"left wing","right wing"}) );
}

int query_auto_load() {
   if(this_player()->query_race() == "faerie")
   return 1;
}

