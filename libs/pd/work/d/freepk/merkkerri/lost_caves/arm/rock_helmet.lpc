#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("rock helmet");
        set_id( ({ "helm", "helmet", "rock helmet" }) );
        set_short("Rock helmet");
        set_long("A helmet carved from rock, it looks a lot of time went into the making of this armour.");
        set_ac(4);
        set_curr_value("gold", 2 + random(5));
        set_limbs( ({ "head" }) );
        set_weight(64);
        set_type("helmet");

}

int query_auto_load() { return 1; }
