#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("fancy greaves");
        set_id( ({ "greaves", "fancy greaves" }) );
        set_short("Fancy studded leather greaves.");
        set_long("These greaves are made from the highest quality leather, and studded with large iron studs. These greaves were stolen by Captain Chestin years ago. He took them in retribution for his being lowered in rank.");
        set_ac(4);
        set_curr_value("gold", 55 + random(5));
        set_limbs( ({ "right leg", "left leg" }) );
        set_weight(34);
        set_type("leggings");
}

int query_auto_load() {
	if(this_player()->query_level() < 35) return 0;	
	return 1; 
}

