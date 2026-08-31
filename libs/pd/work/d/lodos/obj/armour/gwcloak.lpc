#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("cloak");
   set_short("%^BOLD%^%^GREEN%^gr%^YELLOW%^e%^GREEN%^en "
     "a%^YELLOW%^n%^GREEN%^d wh%^YELLOW%^i%^GREEN%^te "
     "cl%^YELLOW%^o%^GREEN%^ak%^RESET%^");
   set_long("The long white cloak was expertly tailored. The trim of the "
     "cloak is a light green, as well as the hood of the cloak. On the "
     "back of the cloak a holy symbol has been stitched in expertly in "
     "that same green color.");
   set_limbs(({ "head", "torso", "left arm", "right arm", "left leg",
                "right leg" }));
   set_id(({ "cloak", "green and white cloak", "white cloak" }));
   set_weight(4);
   set_ac(1);
   set_type("cloak");
    set_curr_value("gold", 25);
}

int query_auto_load() {
   if (this_player()->query_level() >= 15) return 1;
}
