/*
** Done by Ilzarion (badly)
** Cyanide cleaned it up a bit.
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
    set_bonus(5);
    set_weapon_type("sword/long");
    set("id", ({ "sword" }) );
    set("short", "vorpal sword of lightning");
    set("long", @LONG
This is a great blade, about the size of a longsword. It consists
of a handle of some unknown black metal, and a crackling, writhing
blade-like plane of electrical energy.
LONG
    );
    set("name", "vorpal sword of lightning");

    set_verbs( ({ "attack", "swing at", "stab at", "slash at" }) ) ;
    set("damage_type", "electricity"); 
    //set("prevent_get", 1);
    //set("prevent_insert", 1);
    set("value", 10000);
}

int hit_func(object targ, int damage){
    int num;

    switch( (int)targ->query("size") ) {
    case 0..4 : num = 3; break;
    case 5..8 : num = 2; break;
    case 9..20 : num = 1; break;
    default : num = 0; break;
    }

    if (random(20)<num){
	write ("Your vorpal sword severs the head of your opponent!\n");
	tell_object(targ,wrap("You are struck in the neck by a vicious blow!"));

	damage *= 10;
    }

    return damage;
}


