#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("boots");
   set_short("pixie boots");
   set_id(({ "boots", "pixie boots" }));
   set_long("These boots are made of the blades of a tangleweed that have been woven into soft boots.  They are held sturdy by a minor spell of enchantment cast by the tree pixies.");
   set_weight(10);
   set("value", 220);
   set_type("boots");
   set_limbs(({ "right foot", "left foot" }));
   set_ac(5);
   
}
int query_auto_load() {
   if (this_player()->query_level() > 18) return 1;
}
