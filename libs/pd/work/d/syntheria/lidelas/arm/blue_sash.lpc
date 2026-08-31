#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("blue sash");
        set_id( ({ "blue sash", "sash", "vest" }) );
        set_short("%^BOLD%^%^BLUE%^Blue Sash%^RESET%^");
        set_long("A bright blue sash that the guards of Lidelas wear to show their position.");
        set_ac(1);
        set_curr_value("copper", 5 + random(5));
        set_limbs( ({ "torso" }) );
        set_weight(5 + random(2));
        set_type("vest");

}



int query_auto_load() { return 1; }
