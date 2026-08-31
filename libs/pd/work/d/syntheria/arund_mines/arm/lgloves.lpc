#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("work gloves");
        set_id( ({ "work gloves", "gloves" }) );
        set_short("Work Gloves");
        set_long("Work gloves made from a hardy leather. They are terribly worn with several tears starting to form around the knuckles.");
        set_ac(1);
        set_curr_value("copper", 2 + random(5));
        set_limbs( ({ "left hand", "right hand" }) );
        set_weight(3 + random(2));
        set_type("gloves");

}



int query_auto_load() { return 1; }
