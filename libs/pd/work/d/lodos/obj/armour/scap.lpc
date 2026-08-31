#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("cap");
   set_short(
     "%^RESET%^%^BLUE%^a ma%^MAGENTA%^gi%^BLUE%^c%^MAGENTA%^ia%^BLUE%^ns "
     "c%^MAGENTA%^a%^BLUE%^p%^RESET%^");
   set_long("The magicians cap is a pointed cap embroidered with stars "
     "and moons. It is designed much like a witch's cap. The stars and "
     "moons are a dark magenta against a night blue background.");
   set_limbs(({ "head" }));
   set_id(({ "cap", "star cap", "magicians cap", "hat" }));
   set_weight(3);
   set_ac(1);
   set_type("helmet");
    set_curr_value("silver", 325);
}

int query_auto_load() {
   if (this_player()->query_level() >= 20) return 1;
}
