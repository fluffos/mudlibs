#include <std.h>
inherit ARMOUR;
void create() {
 ::create();
   set_name("ironboots");
   set_short("iron boots");
   set_id(({ "boots", "iron boots" }));
   set_long("These boots are horribly heavy and make it difficult to walk in. However, they provide excellent protection");
   set_weight(20);
   set_curr_value("gold", 120);
   set_type("boots");
   set_limbs(({ "right foot", "left foot" }));
   set_ac(5);
   
}
int query_auto_load() {
   if (this_player()->query_level() > 30) return 1;
}
