#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("studded armour");
        set_id( ({ "studded armour", "armour", "armor" }) );
        set_short("Studded armour");
        set_long("A sturdy piece of leather armour of reinforced with metal studs.");
        set_ac(3);
        set_curr_value("copper", 29 + random(10));
        set_limbs( ({ "torso", "right arm", "left arm" }) );
        set_weight(15 + random(8));
        set_type("armour");

}



int query_auto_load() { return 1; }
