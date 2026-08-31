#include <std.h>                                                                                                                

inherit ARMOUR;                                                                                                                 

int can_wear();
int query_auto_load();

void create() 
{ 
    ::create();  
        set_name("dino scale armour");
        set_id( ({ "dino scale armour", "armour", "armor", "dino scale armor", "dino armour", "dino armor" }) );
        set_short("%^GREEN%^%^BOLD%^D%^RESET%^%^GREEN%^i%^BOLD%^n%^RESET%^%^GREEN%^o %^BOLD%^s%^RESET%^%^GREEN%^c%^BOLD%^a%^RESET%^%^GREEN%^l%^BOLD%^e %^RESET%^%^GREEN%^a%^BOLD%^r%^RESET%^%^GREEN%^m%^BOLD%^o%^RESET%^%^GREEN%^u%^BOLD%^r%^RESET%^");
        set_long("A large heavy set of armour made from the scales of dinosaurs.");
        set_ac(12);
        set_curr_value("gold", 40 + random(30));
        set_limbs( ({ "torso", "right arm", "left arm", "right leg", "left leg" }) );
        set_weight(75);
        set_type("body armour");
}

int query_auto_load()
{
    if (this_player()->query_level() > 50) return 1;
    return 0;
}
