#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(3);
    set_weapon_type("spear");
    set ("value",1000);
    set ("mass", 10);
    set ("size", 5);
    set("weapon", 1);
    set("damage", ({2, 12}));
    set("nosecond", 1);
    set("weapon_type", "Polearms");      
    set("id", ({ "scythe", "scythe of flame" }) );
    set("short", "scythe of flame");
    set("long", @LONG
Powerful flames emmanate from the blade
LONG
    );
    set("name", "scythe of flame");
    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;

    set ("hit_func", 1);
}

int hit_func(object targ, int damage){

    targ->receive_damage( (random(10)+3), "fire", environment(this_object()), 1);
    targ->set("last_attacker", environment(this_object()));

    return damage;
}
