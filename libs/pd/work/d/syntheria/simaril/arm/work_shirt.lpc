#include <std.h>                                                               

inherit ARMOUR;                                                                

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("shirt");
        set_id( ({ "work shirt" }) );
        set_short("Work shirt");
        set_long("A thin cloth shirt worn by the dock workers "
        		 "of Simaril. It is very thin and loose, it would "
        		 "make it very comfortable."
		);
        set_ac(1);
        set_curr_value("gold", 10 + random(5));
        set_limbs( ({ "torso" }) );
        set_weight(2);
        set_type("shirt");
}

int query_auto_load() { return 1; }
