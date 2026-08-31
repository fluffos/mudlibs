#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("boots");
   set_short("%^BOLD%^%^WHITE%^wh%^YELLOW%^i%^WHITE%^te le%^YELLOW%^ath%^WHITE%^er bo%^YELLOW%^o%^WHITE%^ts");
   set_long("The long pair of white leather boots are pretty tough for "
     "being so soft and thin.");
   set_limbs(({ "left foot", "right foot" }));
   set_id(({ "boots", "white boots", "leather boots" }));
   set_weight(6);
   set_ac(3);
   set_type("boots");
    set_curr_value("gold", 25);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 1;
}
