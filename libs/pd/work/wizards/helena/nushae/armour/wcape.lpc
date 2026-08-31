#include <std.h>
inherit ARMOUR;

void create() {
  ::create();
    set_name("cape");
    set_short("%^BOLD%^%^GREEN%^weed cape%^RESET%^");
    set_long("A cape which goes from the neck down to the legs of the wearer. Made of soft %^BOLD%^%^GREEN%^seaweed%^RESET%^, the wearer's comfort is confidently reassured.");
    set_limbs(({ "torso", "left leg", "right leg" }));
    set_id(({ "cape", "weed cape" }));
    set_weight(3);
    set_ac(5);
    set_type("cloak");
    set_curr_value("gold", 30);
}

int query_auto_load() {
    if (this_player()->query_level() >=10) return 1;
}
