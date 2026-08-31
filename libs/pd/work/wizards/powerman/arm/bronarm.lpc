#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("soldier armor");
set_short("%^YELLOW%^Heavy Bronze Armour%^RESET%^");
set_long("This suit of bronze armour of feels quite heavy. There are many scratches on the armour combat from previous use. It looks like it can offer good protection.");
set_wear("You are weighed down as you don the suit of armour.");
set_remove("You feel unsafe and much lighter.");
set_id(({"armour", "bronze armour"}));
set_ac(9);
set_weight(130);
set_curr_value("electrum",250);
set_type("armour");
set_limbs(({"torso", "left arm", "right arm", "left leg", "right leg"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }

