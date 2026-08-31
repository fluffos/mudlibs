#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("cap");
        set_id( ({ "cap", "hat" }) );
        set_short("%^GREEN%^Cap%^RESET%^");
        set_long("A small green cap, it looks rather old.");
        set_ac(1);
        set_curr_value("copper", 10 + random(6));
        set_limbs( ({ "head" }) );
        set_weight(8 + random(8));
        set_type("hat");

}

int query_auto_load() { return 1; }
