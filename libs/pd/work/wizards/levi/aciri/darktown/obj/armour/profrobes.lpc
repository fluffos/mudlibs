#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("robes");
   set_short("%^BOLD%^%^BLACK%^a pr%^RESET%^%^ORANGE%^oph%^BOLD%^%^BLACK%^et'%^RESET%^%^ORANGE%^s "
     "ro%^BOLD%^%^BLACK%^bes%^RESET%^");
   set_long("The robes are black with a golden line around the edge of the front "
     "of the robe. The robes themselves almost look evil.");
   set_weight(5);
   set_id(({ "robes", "robe", "phrophet's robes" }));
   set_ac(7);
   set_type("robe");
   set_value(257);
   set_limbs(({ "torso", "left arm", "right arm", "left leg", "right leg" }));
}

int query_auto_load() {
   if (this_player()->query_alignment() <= 500) return 3;
}
