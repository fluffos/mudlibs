
#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("skull belt");
    set_short("%^BOLD%^%^BLACK%^s%^WHITE%^k%^RESET%^u%^BOLD%^%^WHITE%^l%^BLACK%^l b%^WHITE%^e%^RESET%^l%^BOLD%^%^BLACK%^t%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This belt is lined with crystal skulls.%^RESET%^");
    set_id( ({ "belt" , "skull belt" }) );
set_ac(2);
    set_mass(15);
    set_curr_value("gold",100+random(40));
    set_type("belt");
    set_limbs( ({ "torso"}) );
}

int query_auto_load() { if (this_player()->query_level() < 40) return 0;

 return 1;
}
