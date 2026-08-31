#include <std.h>
inherit WEAPON;

create() {
::create();
set_id(({"spear", "swamp spear"}));
set_name("spear");
set_short("swamp spear");
set_long("A spear made of a long wooden shaft and sharpened stone head.  The wood is often rotten and coated in thick slime from lack of care.");
set_weight(15);
set("skill level", 90);
set_curr_value("gold",100);
set_wc(13);
set_ac(0);
set_type("projectile");
set_hands(2);
set_wield("Your hands stick to the slime coating the spear.");
}

int query_auto_load() {
if(this_player()->query_level() < 20) return 0;
return 1; }
