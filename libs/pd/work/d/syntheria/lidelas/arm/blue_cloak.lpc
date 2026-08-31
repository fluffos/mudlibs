#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("blue cape");
        set_id( ({ "blue cape", "cape" }) );
        set_short("%^BLUE%^Blue cape%^RESET%^");
        set_long("A simple blue cape, it is a very dark blue.");
        set_ac(1);
        set_curr_value("copper", 12 + random(5));
        set_limbs( ({ "torso", "right arm", "left arm" }) );
        set_weight(2 + random(2));
        set_type("cloak");

}



int query_auto_load() { return 1; }
