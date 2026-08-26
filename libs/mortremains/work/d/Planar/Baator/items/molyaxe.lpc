
#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(5);
    set_weapon_type("axe/two-handed");
    set("id", ({ "axe" }) );
    set("short", "Vorpal Axe Of Dancing");
    set("long", @LONG
The much feared weapon of the molydeus
LONG
    );
    set("name", "vorpal axe of dancing");

    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("hit_func", 1);
    //set("prevent_drop", 1);
    //set("prevent_get", 1);
    //set("prevent_insert", 1);
set("nosecond", 1);
    set("value", 35000);
    set("unwield_func", "unwield_func");
    set("nosecond", 1);
}

int hit_func(object targ, int damage){
    int size, num;

    size = targ->query("size");

    if (size < 0) size = 1;
    switch(size) {
    case 0..5 : num = 3; break;
    case 6..8 : num = 2; break;
    case 9..19 : num = 1; break;
    default : return damage; break;
    }
    if (random(20)<num){
	write ("Your Vorpal axe severs the head of your opponent!\n");
	tell_object(targ,wrap("You are struck in the neck by a vicious blow!"));

damage = (damage*5);
    }
    return damage;
}


