#include <std.h>                                                               

inherit ARMOUR;                                                                

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("cuirass");
        set_id( ({ "cuirass", "breastplate" }) );
        set_short("Cuirass");
        set_long("A common type of breastplate used by the Syntherian army. "
        		 "This particular cuirass was taken from the body of a young "
        		 "soldier by Captain Chestin after he murdered the young man "
        		 "for cheating in a poker game."
		);
        set_ac(8);
        set_curr_value("gold", 100 + random(15));
        set_limbs( ({ "torso" }) );
        set_weight(36);
        set_type("armour");
}

int query_auto_load() 
{ 
	if(this_player()->query_level() < 35) return 0;	
	return 1; 
}
