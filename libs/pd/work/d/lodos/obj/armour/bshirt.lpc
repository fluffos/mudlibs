#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("shirt");
   set_short("%^BOLD%^%^BLUE%^a%^CYAN%^ t%^BLUE%^i%^CYAN%^ny bl%^BLUE%^u%^CYAN%^e "
     "sh%^BLUE%^i%^CYAN%^rt%^RESET%^");
   set_id(({ "shirt", "tiny shirt", "blue shirt", "tiny blue shirt" }));
   set_long("Made of some remarkable material, this shirt can be stretched to "
     "fit just about anyone despite the shirt's small size. The silky soft "
     "material this shirt has been crafted of is a light blue colour.");
   set_weight(3);
    set_curr_value("gold", 20);
   set_type("shirt");
   set_limbs(({ "right arm", "left arm", "torso" }));
   set_ac(1);
}

int query_auto_load() { if (this_player()->query_level() >= 3) return 1; }
