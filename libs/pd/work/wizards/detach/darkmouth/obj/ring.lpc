#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Skull Ring");
    set_short("%^BOLD%^BLACK%^s%^RESET%^BOLD%^k%^RESET%^u%^BOLD%^l%^RESET%^BOLD%^BLACK%^l%^RESET%^ %^BOLD%^BLACK%^r%^RESET%^BOLD%^i%^RESET%^n%^BOLD%^BLACK%^g%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^A small platinum band, a crystal skull hovers about the band.");
    set_id( ({ "ring" , "skull ring" }) );
    set_ac(2);
    set_mass(2);
    set_curr_value("gold",50+random(40));
    set_type("ring");
    set_limbs( ({ "left hand"}) );
}

int query_auto_load() { if (this_player()->query_level() < 40) return 0;

    return 1;
}
