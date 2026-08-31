#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("red cloak");
        set_id( ({ "cloak", "cape", "red cloak" }) );
        set_short("%^RED%^Red Cloak%^RESET%^");
        set_long("A large cloak made of bright red fabric.");
        set_ac(2);
        set_curr_value("copper", 24 + random(5));
        set_limbs( ({ "torso", "right arm", "left arm" }) );
        set_weight(12 + random(4));
        set_type("cloak");

}



int query_auto_load() { return 1; }
