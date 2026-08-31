#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("tunic");
    set_short("%^GREEN%^dem%^RESET%^BOLD%^o%^RESET%^n%^BOLD%^s%^RESET%^GREEN%^kin%^ t%^RESET%^BOLD%^u%^RESET%^n%^BOLD%^i%^RESET%^GREEN%^c%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This Tunic was formed from the skin of a demon.");
    set_id( ({ "tunic" , "demonskin tunic" }) );
    set_ac(2);
    set_mass(11);
    set_curr_value("gold",80+random(40));
    set_type("tunic");
    set_limbs( ({ "head","torso","left arm","right arm" }) );
}

int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}
