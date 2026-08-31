#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^BOLD%^%^BLACK%^S%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^a%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^w %^BOLD%^%^BLACK%^A%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^m%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^It seems to be just a illusion.");
    set_id( ({ "armour" , "shadow armour", "shadowarmour" }) );
    set_ac(7);
    set_mass(15);
    set_curr_value("gold",120+random(40));
    set_type("body armour");
    set_limbs( ({ "torso","right arm","left arm" }) );
}

int query_auto_load()
{                                   
if (this_player()->query_level() > 10) return 1;
if (wizardp(this_player())) return 1;
 return 0;
}     
