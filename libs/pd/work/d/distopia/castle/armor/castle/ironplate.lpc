#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ironplate");
   set_short("Iron Platemail");
   set_id(({ "iron plate", "plate", "iron platemail", "iron", "platemail", "armour" }));
   set_long("This peice of armor is very heavy but very tough.");
   set_weight(75);
    set_curr_value("gold", 150);
   set_type("armour");
   set_limbs(({ "torso" }));
   set_ac(11);
}
int query_auto_load() { if (this_player()->query_level() >= 30) return 1; }
