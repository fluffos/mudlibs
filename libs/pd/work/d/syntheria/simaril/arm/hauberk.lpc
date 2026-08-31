#include <std.h>                                                               

inherit ARMOUR;                                                                

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("hauberk");
        set_id( ({ "hauberk","shirt" }) );
        set_short("Hauberk");
        set_long("A shirt made of from mail. "
        		 "It extends down to the legs. "
        		 "This is a rare and old armour stolen by "
        		 "Thyas a long time ago from a soldier he "
        		 "had killed in a large naval battle."
		);
        set_ac(2);
        set_curr_value("gold", 35 + random(10));
        set_limbs( ({ "torso", "right leg", "left leg" }) );
        set_weight(14);
        set_type("shirt");
}

int query_auto_load() 
{ 
	if(this_player()->query_level() < 35) return 0;
	return 1; 
}
