#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("plate");
    set_short("%^BOLD%^%^BLACK%^Dark Plate%^RESET%^");
    set_long("%^BOLD%^%^BLACK%^This Plate was formed by the evil drow pyromancer. The "
           "%^BOLD%^%^BLACK%^myth has it told that the true powers of hell are in it.");
    set_id( ({ "armour" , "plate","dark plate" }) );
    set_ac(11);
    set_wear("%^BOLD%^%^BLACK%^You Hear the Crackle of voices from far off.%^RESET%^");
    set_remove("%^BOLD%^%^WHITE%^The voices fade away.%^RESET%^");
    set_mass(80);
    set_curr_value("gold", 140);
    set_type("armour");
    set_limbs( ({ "torso","first arm","second arm","third arm","fourth arm" })
);
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 if(this_player()->query_level() < 50) return 0;
 return 1;
}
