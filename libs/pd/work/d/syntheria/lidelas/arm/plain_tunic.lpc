#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("plain tunic");
        set_id( ({ "tunic", "plain tunic" }) );
        set_short("Plain tunic");
        set_long("A simple tunic made of cloth.");
        set_ac(1);
        set_curr_value("copper", 20 + random(5));
        set_limbs( ({ "left arm", "right arm", "torso", "left leg", "right leg" }) );
        set_weight(12 + random(3));
        set_type("tunic");

}



int query_auto_load() { return 1; }
