#include <std.h>
inherit ARMOUR;
int extra_worn();
void create() {
::create();
  set_name("  ");
  set_id(({ "robe", "robe of shadows", "shadow robe" }));
  set_short("a Robe of Shadows");
  set_long(
   "These robes are quite nice.  Made from a black animal skin, they "
   "are incredibly luxurious, but inffective as armour.  They do provide "
   "adequate cloaking in the night though, when a rogueish person might "
   "need the stealth advantage.");
  set_ac(0);            
  set_mass(12);
  set_value(12);
  set_type("robes");
  set_limbs(({"left leg", "right leg", "torso", "head", "right arm", "left
arm"}));
}
int extra_worn() {
    if((int)this_player()->query_races() ="raknid") {
        set_limbs(({ "left foreleg", "right foreleg", "left rear leg", "right rear leg",
                      "first arm", "second arm", "third arm", "fourth arm",
                      "head", "torso", "abdomen",}));
                      

  
    }
     }
}
 int query_auto_load() { if (this_player()->query_level() > 45) return 1; }
