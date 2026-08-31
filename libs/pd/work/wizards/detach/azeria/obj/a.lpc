#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Gold Sandals");
    set_short("%^YELLOW%^Go%^BOLD%^%^WHITE%^l%^RESET%^d %^YELLOW%^Sand%^BOLD%^%^WHITE%^al%^RESET%^s");
    set_long("These sandals are made from the richest gold in all of Azeria.");
    set_id( ({ "sandals" , "gold sandals" }) );
    set_ac(7);
    set_mass(10);
    set_curr_value("gold",150+random(40));
    set_type("boots");
    set_limbs( ({ "right foot","left foot" }) );
}                  
int query_auto_load()
{
    if (wizardp(this_player())) return 1;
    return 1;
}
