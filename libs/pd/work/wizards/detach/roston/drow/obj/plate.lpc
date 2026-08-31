#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("plate");
    set_short("%^BOLD%^%^BLACK%^Dark Plate%^RESET%^");
    set_long("This Plate was formed by the evil drow pyromancer. The "
           "myth has it told that the true powers of hell are in it.");
    set_id( ({ "armour" , "plate","dark plate" }) );
    set_ac(13);
    set_wear("%^BOLD%^%^BLACK%^You Hear the Crackle of voices from far off.");
    set_remove("BOLD%^%^WHITE%^The voices fade away.");
    set_mass(30);
    set_value(20);
    set_type("body armour");
    set_limbs( ({ "torso","head","first arm","second arm","third arm","fourth arm" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
