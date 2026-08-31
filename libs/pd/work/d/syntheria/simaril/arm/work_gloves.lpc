#include <std.h>                                                               

inherit ARMOUR;                                                                

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("gloves");
        set_id( ({ "work gloves" }) );
        set_short("Work gloves");
        set_long("These are the gloves worn by the dock workers "
				 "of Simaril. They are made of tough leather and "
				 "are meant to protect the hands from the boxes "
				 "and barrels that are moved daily at the docks."
				 );
        set_ac(1);
        set_curr_value("gold", 10 + random(5));
        set_limbs( ({ "left hand", "right hand" }) );
        set_weight(2);
        set_type("gloves");

}

int query_auto_load() { return 1; }
