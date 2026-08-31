#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("tunic");
    set_short("%^GREEN%^Dem%^BOLD%^%^WHITE%^o%^RESET%^n%^BOLD%^%^WHITE%^s%^RESET%^%^GREEN%^kin t%^BOLD%^%^WHITE%^u%^RESET%^n%^BOLD%^%^WHITE%^i%^RESET%^%^GREEN%^c%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^This Tunic was formed from the skin of a demon.");
    set_id( ({ "tunic" , "demonskin tunic" }) );
    set_ac(6);
    set_mass(11);
    set_value(33);
    set_type("tunic");
    set_limbs( ({ "head","torso","left arm" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
