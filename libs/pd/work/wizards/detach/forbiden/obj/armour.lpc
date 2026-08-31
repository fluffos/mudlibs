#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("armour");
    set_short("%^BOLD%^%^GREEN%^F%^BLACK%^o%^GREEN%^r%^BLACK%^b%^GREEN%^i%^BLACK%^dd%^GREEN%^e%^BLACK%^n %^BOLD%^%^BLACK%^A%^BOLD%^%^GREEN%^r%^BLACK%^m%^BOLD%^%^GREEN%^o%^BLACK%^u%^BOLD%^%^GREEN%^r%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This Armour is worn by the ruler of the forbidden forest, it is made from a rare metal.%^RESET%^");
    set_id( ({ "armour" , "forbidden armour" }) );
    set_ac(10);
    set_mass(50);
    set_value(100);
    set_type("body armour");
    set_limbs( ({ "head","torso","right arm","left arm" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
