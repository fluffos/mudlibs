#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("simple cloth jerkin");
        set_id( ({ "simple cloth jerkin", "jerkin", "cloth jerkin", "armour", "armor", "vest" }) );
        set_short("Simple cloth jerkin");
        set_long("A simple jerkin made of cloth, it doens't look like it would provide much protection.");
        set_ac(1);
        set_curr_value("copper", 10 + random(5));
        set_limbs( ({ "torso" }) );
        set_weight(5 + random(2));
        set_type("vest");

}



int query_auto_load() { return 1; }
