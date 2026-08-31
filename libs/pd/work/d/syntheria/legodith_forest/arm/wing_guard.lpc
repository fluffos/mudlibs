#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("wing guard");
        set_id( ({ "wing armour", "wing guard", "armour", "armor" }) );
        set_short("Wing guard");
        set_long("A thin protective layer of cloth for wings.");
        set_ac(1);
        set_curr_value("copper", 12 + random(5));
        set_limbs( ({ "left wing", "right wing" }) );
        set_weight(2 + random(2));
        set_type("wing armour");

}



int query_auto_load() { return 1; }

