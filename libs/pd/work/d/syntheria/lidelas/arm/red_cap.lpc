#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("red cap");
        set_id( ({ "cap", "helm", "helmet", "red cap" }) );
        set_short("%^RED%^Red cap%^RESET%^");
        set_long("A thin cap made of red cloth.");
        set_ac(2);
        set_curr_value("copper", 18 + random(5));
        set_limbs( ({ "head" }) );
        set_weight(8 + random(2));
        set_type("helmet");

}



int query_auto_load() { return 1; }
