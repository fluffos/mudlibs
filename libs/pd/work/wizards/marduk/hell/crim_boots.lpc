#include <std.h>
inherit ARMOUR;

void create() {
::create();
    set_name("boots");
    set_short("%^RED%^Cr%^ORANGE%^i%^RED%^ms%^ORANGE%^o%^RED%^n B%^ORANGE%^oo%^RED%^ts");
    set_long("This is just a small piece, of the great Crimson Armour.");
    set_id(({"boots", "crimson boots"}));
    set_ac(7);
    set_mass(10);
    set_value(400);
    set_type("armour");
    set_limbs(({"right foot", "left foot"}));
}
int query_auto_load() { if (this_player()->query_level() > 19) return 1; }
