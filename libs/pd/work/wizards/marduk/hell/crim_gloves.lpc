#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("gloves");
    set_short("%^BLUE%^Cr%^RED%^ims%^BOLD%^%^BLACK%^on Gl%^RESET%^%^RED%^ov%^BLUE%^es");
    set_long("This is just a small piece, of the great Crimson Armour.");
    set_id(({"gloves", "crimson gloves"}));
    set_ac(6);
    set_mass(8);
    set_value(350);
    set_type("armour");
    set_limbs(({"right hand", "left hand"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
