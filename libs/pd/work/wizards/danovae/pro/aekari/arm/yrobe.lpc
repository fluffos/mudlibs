
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("robe");
   set_id( ({ "robe" }) );
   set_short("%^YELLOW%^%^BOLD%^Yellow Aekari Robe%^RESET%^");
   set_long(
     "A robe made from a cotton fiber. It is not terribly ornate "
     "nor is it terribly strong. It looks to be well kept. "
   );
   set_ac(5);
   set_mass(15);
   set_value(30);
   set_type("robe");
   set_limbs( ({ "right arm","left arm","torso","right leg","left leg" }) );
}

int query_auto_load() {
   if(this_player()->query_race() == "faerie")
   return 1;
}

