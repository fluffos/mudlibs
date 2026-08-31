#include <std.h>
inherit ARMOUR;
 
void create() {
::create();
set_name("bronze boots");
set_short("%^ORANGE%^Bronze %^YELLOW%^Plated Boots%^RESET%^");
set_long("This pair of boots is made out of tough hide for durability. It is
plated on the outside with bronze to ensure protection.");
set_wear("Your feet don't move as quickly as you feel cramped.");
set_remove("Your feet starts to spasm from relaxation.");
set_id(({"boots"}));
set_ac(5);
set_weight(30);
set_curr_value("electrum",250);
set_type("boots");
set_limbs(({"left foot", "right foot"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
