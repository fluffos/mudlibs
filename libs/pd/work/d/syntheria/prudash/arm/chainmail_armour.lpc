#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("chainmail armour");
        set_id( ({ "chainmail armour", "armour", "armor" }) );
        set_short("Chainmail armour");
        set_long("Armour made from old chainmail, it looks sturdy.");
        set_ac(4);
        set_curr_value("copper", 35 + random(10));
        set_limbs( ({ "torso", "right arm", "left arm" }) );
        set_weight(25 + random(20));
        set_type("armour");

}



int query_auto_load() { return 1; }
