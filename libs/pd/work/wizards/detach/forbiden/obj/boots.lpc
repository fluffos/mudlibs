#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("boots");
    set_short("%^BOLD%^%^WHITE%^Wo%^RESET%^%^GREEN%^lfsk%^BOLD%^%^WHITE%^in B%^RESET%^%^GREEN%^oo%^BOLD%^%^WHITE%^ts%^RESET%^");
    set_long("These boots are made from the skin of a huge silver wolf.");
    set_id( ({ "boots" , "wolfskin boots" }) );
    set_ac(5);
    set_mass(10);
    set_value(25);
    set_type("boots");
    set_limbs( ({ "left foot","right foot" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
