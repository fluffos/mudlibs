#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("black robe");
        set_id( ({ "black robe", "robe" }) );
        set_short("%^BOLD%^%^BLACK%^Black robe%^RESET%^");
        set_long("A long flowing robe made from black cloth.");
        set_ac(2);
        set_curr_value("copper", 24 + random(5));
        set_limbs( ({ "torso", "right arm", "left arm", "left leg", "right leg" }) );
        set_weight(12 + random(4));
        set_type("cloak");

}



int query_auto_load() { return 1; }
