#include <std.h>

inherit ARMOUR;

void create() {
  ::create();
    set_name("robe");
    set_short("A High Priest Robe");
    set_long("A simple robe.");
    set_id(({"high priest robe", "robe"}));
    set_ac(1);            
    set_mass(10);
    set_curr_value("gold",5+random(5));
    set_type("robes");   
    set_limbs(({"right arm", "left arm", "right leg", "left leg", "torso","head" }));

}
int query_auto_load() { 
    if(this_player()->query_level() >1) 
        return 1;
    return 0;
}



