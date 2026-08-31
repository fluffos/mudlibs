#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Black Leggings");
    set_short("%^BOLD%^%^BLACK%^Bl%^WHITE%^a%^BLACK%^ck leg%^WHITE%^gi%^BLACK%^ngs%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^These leggings seem to swirl all around, as if a mist was caught
in-side them.");
    set_id( ({ "leggings" , "black leggings" }) );
    set_ac(4);
    set_mass(12);
    set_curr_value("gold",90+random(40));
    set_type("leggings");
    set_limbs( ({ "right leg","left leg"}) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
