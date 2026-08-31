#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("robes");
   set_short("%^RESET%^%^CYAN%^the robe of "
    "%^BOLD%^K%^RESET%^%^CYAN%^i%^BOLD%^n%^RESET%^%^CYAN%^g%^BOLD%^s%^RESET%^");
   set_long("This robe has been worn by many kings since it was first woven. "
     "This robe alone has been the bane of three seperate assassination "
     "attempts. The inside of the robe has steel threads woven into a thin "
     "layer under the saphire blue cloth.");
   set_weight(17);
   set_id(({ "robes", "robe of kings", "robe" }));
   set_type("robe");
   set_ac(7);
   set_value(305);
   set_limbs(({ "torso", "left leg", "right leg", "right arm", "left arm" }));
}

int query_auto_load() { if (this_player()->query_level() >= 25) return 3; }
