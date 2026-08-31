#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("steelchainmail");
   set_short("steel chainmail");
   set_id(({"steel chainmail", "steel chain", "chain", "chainmail" }));
   set_long("This light piece of chainmail fits comfortably over whatever body armor a person has providing extra protection");
   set_weight(40);
   set_curr_value("gold", 250);
   set_type("chainmail");
   set_limbs(({ "torso", "right arm", "left arm" }));
   set_ac(4);
   
}
int query_auto_load() {
   if (this_player()->query_level() > 20) return 1;
}
