#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("rusty helmet");
        set_id( ({ "rusty helmet", "helmet" }) );
        set_short("%^ORANGE%^Rusty helmet%^RESET%^");
        set_long("An old helmet that has been through a few too many battles.");
        set_ac(3);
        set_curr_value("copper", 30 + random(15));
        set_limbs( ({ "head" }) );
        set_weight(10 + random(10));
        set_type("helmet");

}



int query_auto_load() { return 1; }

