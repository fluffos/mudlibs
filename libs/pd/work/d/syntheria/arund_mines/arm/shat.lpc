#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("straw hat");
        set_id( ({ "straw hat", "hat" }) );
        set_short("Straw hat");
        set_long("An old hat weaved from straw. It does not look comfortable.");
        set_ac(0);
        set_curr_value("copper", 1 + random(5));
        set_limbs( ({ "head" }) );
        set_weight(1 + random(2));
        set_type("helmet");

}

int query_auto_load() { return 1; }
