// A salamander's spear
// Cyanide, 10 Jun 2000

#include <messages.h>

inherit WEAPON;

void create() {
    set_weapon_type("spear");
    set("nosecond", 1);
    set("author", "cyanide");
    set("id", ({ "spear" }) );
    set("short", "a solid steel spear");
    set("long", @LONG
A large spear crafted from a single piece of solid steel. It
appears to have been subjected to a great deal of heat over
long periods of time.
LONG
    );
    set("name", "solid steel spear");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("hit_func", 1);
    set("value", 50);
}

int hit_func(object targ, int damage){
    object env = environment(this_object());

    if (env->query("race") == "salamander") {
	message(MSG_COMBAT, "The salamander's heat burns you!\n",
	  targ);
	targ->receive_damage(damage, "fire");
    }

    return damage;
}


