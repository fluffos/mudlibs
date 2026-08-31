#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("hide gloves");
        set_id( ({ "hide gloves", "gloves" }) );
        set_short("Hide gloves");
        set_long("Gloves made from the hide of some animal.");
        set_ac(3);
        set_curr_value("copper", 40 + random(15));
        set_limbs( ({ "left hand", "right hand" }) );
        set_weight(5 + random(2));
        set_type("gloves");

}



int query_auto_load() { return 1; }

