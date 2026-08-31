#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Flaming Body Armour");
    set_short("%^RED%^Fla%^BOLD%^%^RED%^min%^RESET%^%^ORANGE%^g "
"B%^BOLD%^%^RED%^od%^RESET%^%^RED%^y "
"Ar%^BOLD%^%^RED%^mou%^RESET%^%^ORANGE%^r%^RESET%^");
   set_long("This Armour was formed from bursting Lava pits, "
"found all around Azeria. It was made by a conjuring.");
    set_id( ({"armour","flameing body armour" }) );
    set_ac(10);
    set_mass(29);
    set_curr_value("gold",150+random(40));
    set_type("body armour");
    // set_limbs( ({ "right foot","left foot","torso","head","right leg","left leg"}) );
    set_limbs(({ "first arm", "second arm", "third arm", "fourth arm", "torso", "abdomen"}));
}                  
int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
