/*    /d/Examples/weapon/skill_sword.c
 *    from Nightmare IV
 *    a sword with a skill bonus for those wielding it
 *    created by Nialson@Nightmare 940427
 */

#include <std.h>

#ifdef WEAPON
inherit WEAPON;

void create() {
    ::create();
    set_name("healing sword");
    set_id( ({ "sword", "sword of healing" }) );
    set_adjectives( ({ "healing", "a", "a sword dedicated to" }) );
    set_short("a sword dedicated to healing");
    set_long("It is a very finely made sword, doesn't look very effective.");
    set_mass(200);
    set_value(400);
    set_wc(9);
    set_type("blade");
    set_wield( (: this_object(), "add_bonus" :) );
    set_unwield( (: this_object(), "remove_bonus" :) );
}

int add_bonus() {
    this_player()->add_skill_bonus("healing", 20);
    return 1;
}

int remove_bonus() {
    query_wielded()->add_skill_bonus("healing", -20);
    return 1;
}

void unequip() { 
    if(query_wielded() && remove_bonus()) __ActuallyUnwield();
}
#endif
