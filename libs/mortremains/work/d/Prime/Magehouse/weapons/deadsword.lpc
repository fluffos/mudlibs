#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author", "blood");
    set("short", "Sword of the Dead");
    set("long", @Endtext
This sword has a red hilt holding the blackest blade you've ever seen.
Endtext
    );
    set("id", ({ "sword", "sword of the dead" }) );
    set_weapon_type("sword/long");
    set("name", "sword");
    set_verbs( ({ "attack" , "swing at" , "thrust at" }) );
    set("nosecond",1);
    set_bonus(2);
    set("value", 8000);
}

int hit_func( object targ, int dmg ) {
    object owner;
    int num = random(20);

    // If the target is undead - HE GETS THE HEALING!
    if (targ->query("undead"))
	owner = targ;
    else
	owner = environment(TO);

    // Made in form of a switch, in case any new ideas come up.
    switch(num) {
    case 0..10 : owner->receive_healing( dmg / 10 );
    }

    return dmg;
}

/* EOF */
