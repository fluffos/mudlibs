#include <std.h>
inherit ARMOUR;
 
void create() {
::create();
    set_id(({"tunic", "leaf shirt", "shirt"}));
    set_name("leaf shirt");
    set_short("%^RESET%^GREEN%^Leaf Shirt%^RESET%^");
    set_long("This shirt has been made of two giant leaves from a forest plant. The stem of each leaf is coiled around the other and would sit perfectly on the shoulders.");
    set_mass(10);
    set_curr_value("gold", 70);
    set_ac(2);
    set_type("tunic");
    set_limbs(({"torso"}));
    set_wear("%^RESET%^GREEN%^You slip into the comfortable shirt.%^RESET%^");
}

int query_auto_load() {
    if(this_player()->query_level() > 49) return 1;
    return 0;
}
