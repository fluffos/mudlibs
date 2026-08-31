#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("old tunic");
        set_id( ({ "old tunic", "tunic", "armour", "armor" }) );
        set_short("Old %^RED%^tunic%^RESET%^");
        set_long("An old tunic made from red cloth.");
        set_ac(1);
        set_curr_value("copper", 10 + random(6));
        set_limbs( ({ "torso", "right arm", "left arm" }) );
        set_weight(10 + random(8));
        set_type("tunic");

}



int query_auto_load() { return 1; }
