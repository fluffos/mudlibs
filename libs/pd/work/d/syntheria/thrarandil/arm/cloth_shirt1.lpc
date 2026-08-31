#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("cloth shirt");
        set_id( ({ "shirt", "armour", "armor" }) );
        set_short("%^BOLD%^%^RED%^Cloth shirt%^RESET%^");
        set_long("A new shirt made from fine imported cloth.");
        set_ac(1);
        set_curr_value("silver", 2 + random(5));
        set_limbs( ({ "torso" }) );
        set_weight(5 + random(2));
        set_type("shirt");

}

int query_auto_load() { return 1; }

