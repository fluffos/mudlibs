/*    /d/Examples/weapon/cursed_sword.c
 *    from Nightmare IV
 *    a sword cursing its wielder
 *    created by Nialson@Nightmare 940427
 */

#include <std.h>

#ifdef WEAPON
inherit WEAPON;

void create() {
    ::create();
    set_name("cursed sword of the elves");
    set_id( ({ "sword", "cursed sword" }) );
    set_adjectives( ({ "the", "cursed", "elven" }) );
    set_short("a cursed sword made by the elves");
    set_long("It is a very finely made sword, but it "
      "does not look very effective.");
    set_mass(200);
    set_value(400);
    set_wc(-9);
    set_type("blade");
    set_wield("You fool! You have wielded a cursed sword!");
    set_unwield( (: this_object(), "remove_sword" :) );
    set_prevent_drop( (: this_object(), "can_drop" :) );
}

int remove_sword() {
    if((string)query_wielded()->query_race() == "elf") return 1;
    write("The sword is stuck to your hand and cannot be unwielded!");
    return 0;
}

void unequip() {
    if(query_wielded() && remove_sword()) __ActuallyUnwield();
}

int can_drop(object ob) {
    if(!query_wielded() || query_wielded() != ob) return 1;
    if((string)this_player()->query_race() == "elf") return 1;
    else {
        message("my_action", "The sword refuses to leave your hands!", ob);
        message("other_action", (string)ob->query_cap_name()+" tries to drop "+
          possessive(ob)+" sword, but it will not unwield!", 
          environment(ob), ({ ob }) );
        return 0;
    }
}
#endif
