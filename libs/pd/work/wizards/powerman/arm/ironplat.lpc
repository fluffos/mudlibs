#include <std.h>
inherit ARMOUR;

void create() {
::create();
set_name("iron plate");
set_short("An Iron Plate");
set_long("An iron plate, stick it between your armor to protect yourself.");
set_wear("You shove it between your armour hastily and prepare for battle.");
set_remove("You feel like you are more likely to die without this.");
set_id(({"protector","plate"}));
set_ac(5);
set_weight(30);
set_curr_value("electrum",150);
set_type("armour");
set_limbs(({"torso"}));
}
int query_auto_load() { if (this_player()->query_level() >= 20) return 1; }
