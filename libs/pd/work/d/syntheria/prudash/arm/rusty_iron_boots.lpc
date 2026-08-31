#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("rusty iron boots");
        set_id( ({ "rusty iron boots", "iron boots", "rusty boots", "boots" }) );
        set_short("rusty iron boots");
        set_long("Boots made from hard leather, reinforced with bands of old iron.");
        set_ac(2);
        set_curr_value("copper", 20 + random(20));
        set_limbs( ({ "left foot", "right foot" }) );
        set_weight(20 + random(10));
        set_type("boots");

}



int query_auto_load() { return 1; }
