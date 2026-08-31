#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("gem necklace");
        set_id( ({ "necklace", "gem necklace" }) );
        set_short("Gem necklace");
        set_long("A necklace made from random gems, the gems are polished nicely.");
        set_ac(1);
        set_curr_value("gold", 75 + random(25));
        set_limbs( ({ "head" }) );
        set_weight(12);
        set_type("necklace");

}

int query_auto_load() { return 1; }
