#include <std.h>
#include <castlewall.h>
inherit ARMOUR;
void create() {
::create();
  
    set_name("Scarred Vest");
    set_short("%^BOLD%^%^WHITE%^Scarred Vest%^RESET%^");
    set_long("This vest has seen many battles. The hastily stitched scars on the vest shows where someone caught the owner unawares.");
    set_id(({"vest"}));
    set_ac(1);            
    set_mass(12);
    set_type("vest");
    set_curr_value("gold", 50+random(50));  
    set_wear("The vest slips over your shoulders.") ;
    set_remove("You remove the vest with a shudder.");
    set_limbs(({ "torso"}));
}
 int query_auto_load() { if (this_player()->query_level() > 35) return 1; }

