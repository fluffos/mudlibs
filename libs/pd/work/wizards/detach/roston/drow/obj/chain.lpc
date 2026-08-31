#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Chainmail");
    set_short("%^BOLD%^%^BLACK%^Drow Chainmail%^RESET%^");
    set_long("This Chainmail is worn by the archers of the "
         "drow army, its made of a very lite steel.");
    set_id( ({ "armour" , "chainmail","drow chainmail" }) );
    set_ac(11);
    set_mass(29);
    set_value(20);
    set_type("body armour");
    set_limbs( ({ "torso","head","left leg","right leg" }) );
}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
