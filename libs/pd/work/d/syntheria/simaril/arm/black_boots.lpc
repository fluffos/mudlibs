#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("black boots");
        set_id( ({ "boots", "black boots" }) );
        set_short("%^BOLD%^%^BLACK%^Black boots%^RESET%^");
        set_long("A pair of shiny black boots, made from a fine leather. They look to be made for someone of noble birth.");
        set_ac(2);
        set_curr_value("gold", 25 + random(5));
        set_limbs( ({ "right foot", "left foot" }) );
        set_weight(12);
        set_type("boots");
}

int query_auto_load() {
	if(this_player()->query_level() < 35) return 0;	
	return 1; 
}

