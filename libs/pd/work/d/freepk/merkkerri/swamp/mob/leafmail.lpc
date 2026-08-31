#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("armor");
   set_short("%^GREEN%^Leaf%^YELLOW%^mail%^RESET%^ Armor");
   set_id(({"leafmail", "armor", "armour", "leafmail armor" }));
   set_long("This suit of armor was worn by the Pixie king of the Merkkirri swamp.  It appears as scalemail armor but is made of tiny overlapped leaves.  The king strengthened it with a powerful spell of enchantment.");
   set_weight(60);
   set_curr_value("gold", 110);
   set_type("chainmail");
   set_limbs(({ "torso", "right arm", "left arm" }));
   set_ac(6);
   
}
int query_auto_load() {
   if (this_player()->query_level() > 20) return 1;
}
