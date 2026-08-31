#include <std.h>
inherit ARMOUR;
void create() {
::create();
set_name("Full Plate Spiked Armour");
set_short("%^YELLOW%^Full %^BOLD%^BLACK%^Plate %^RED%^Spiked%^ %^BLACK%^Armour%^RESET%^");
set_long("This full suit of armour was custom built by that masochist Furion. It is large, bulky, and has spikes of ranging sizes all over it.");
set_id(({"armour", "armor", "full plate", "full plate armour"}));
set_ac(7);
set_mass(145);
set_value(0);
set_type("armour");
set_limbs(({ "torso", "left arm", "right arm", "right leg", "left leg", }));
}
int query_auto_load() { if (this_player()->query_level() >=20) return 1; }

