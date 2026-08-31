#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Battle Medallion");
    set_short("Battle Medallion");
    set_long("This medallion is awarded to persons who have shown courage in the midst of battle.");
    set_id(({"medallion", "necklace"}));
    set_ac(0);            
    set_mass(1);
    set_type("medallion");
    set_curr_value("gold", 1);  
    set_limbs(({ "torso"}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }
