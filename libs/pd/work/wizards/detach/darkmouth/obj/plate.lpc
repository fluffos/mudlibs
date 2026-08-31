#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("%^BOLD%^%^BLACK%^D%^WHITE%^e%^RED%^m%^RESET%^%^RED%^o%^BOLD%^%^RED%^n%^WHITE%^i%^BLACK%^c P%^WHITE%^l%^RESET%^%^RED%^a%^BOLD%^%^WHITE%^t%^BLACK%^e%^RESET%^");
    set_short("Demonic Plate");
set_long("%^BOLD%^%^BLACK%^Mist fills your eyes, this plate is formed from a rare metal, it looks as if hunderds of traped souls swim through this plate.%^RESET%^");
    set_id( ({ "plate" , "demonic plate" }) );
    set_ac(9);
    set_mass(55);
    set_curr_value("gold",120+random(40));
    set_type("armour");
    set_limbs( ({ "head","torso"}) );
}

int query_auto_load() { if (this_player()->query_level() < 40) return 0;

 return 1;
} 
