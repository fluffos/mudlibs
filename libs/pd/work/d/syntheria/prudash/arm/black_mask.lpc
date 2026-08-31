#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("black mask");
        set_id( ({ "black mask", "mask" }) );
        set_short("%^BLACK%^%^BOLD%^Black mask%^RESET%^");
        set_long("A dark black mask, meant to hide the face of people who wish to not be identified.");
        set_ac(1);
        set_curr_value("copper", 20+ random(10));
        set_limbs( ({ "head" }) );
        set_weight(10 + random(6));
        set_type("mask");

}

int query_auto_load() { return 1; }
