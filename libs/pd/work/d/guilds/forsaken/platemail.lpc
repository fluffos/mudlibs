#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Raknid Platemail");
    set_short("%^BOLD%^%^BLACK%^Raknid %^WHITE%^P%^BLACK%^l%^WHITE%^a%^BLACK%^t%^WHITE%^e%^BLACK%^m%^WHITE%^a%^BLACK%^i%^WHITE%^l%^RESET%^");
    set_long("Forged from the %^BOLD%^%^BLUE%^For%^RESET%^%^WHITE%^sa%^BOLD%^%^BLUE%^ken%^RESET%^ guild this is very good armour");
    set_id (({"plate", "armour", "platemail"}));
    set_ac(1);
    set_mass(60);
    set_curr_value("gold", 150);
    set_type("leggings");
    set_limbs (({"right rear leg", "right foreleg", "left rear leg", 
        "left foreleg", "abdomen"}));
}
int query_auto_load() 
{
    if(this_player()->query_guild() == "forsaken") return 1; else return 0;
}
