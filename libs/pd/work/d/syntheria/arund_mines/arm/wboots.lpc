#include <std.h>                                                               

inherit ARMOUR;                                                                

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("work boots");
        set_id( ({ "work boots", "boots" }) );
        set_short("Work Boots");
        set_long("A solid pair of work boots used in the Arund mines. They are made from the of the toughest leather around.");
        set_ac(1);
        set_curr_value("copper", 25 + random(5));
        set_limbs( ({ "left foot", "right foot" }) );
        set_weight(6 + random(2));
        set_type("boots");

}

int query_auto_load() { return 1; }
