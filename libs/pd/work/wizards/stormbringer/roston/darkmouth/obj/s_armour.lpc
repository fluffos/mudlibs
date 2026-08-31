#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^BOLD%^%^BLACK%^S%^RESET%^%^BLUE%^h%^BOLD%^%^BLACK%^a"
"%^RESET%^%^BLUE%^d%^BOLD%^%^BLACK%^o%^RESET%^%^BLUE%^w"
" %^BOLD%^%^BLACK%^A%^RESET%^%^BLUE%^r%^BOLD%^%^BLACK%^m"
"%^RESET%^%^BLUE%^o%^BOLD%^%^BLACK%^u%^RESET%^%^BLUE%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^It seems to be just a illusion.");
    set_id( ({ "armour" , "shadow armour", "shadowarmour" }) );
    set_ac(11);
    set_mass(19);
    set_curr_value("gold", 120);
    set_type("body armour");
    set_limbs( ({ "torso","head","right arm","left arm" }) );
}

int query_auto_load()
{                                   
if (this_player()->query_level() > 10) return 1;
 return 0;
}                 

