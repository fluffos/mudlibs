#include <std.h>                                                               

inherit ARMOUR;                                                                

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("overalls");
        set_id( ({ "cloth overalls", "overalls" }) );
        set_short("Overalls");
        set_long("A large pair of overalls, they are made of cloth. "
				 "These overalls are the ones worn by the dock workers "
				 "of Simaril.");
        set_ac(1);
        set_curr_value("gold", 10 + random(5));
        set_limbs( ({ "left leg", "right leg", "torso" }) );
        set_weight(8 + random(2));
        set_type("pants");

}

int query_auto_load() { return 1; }
