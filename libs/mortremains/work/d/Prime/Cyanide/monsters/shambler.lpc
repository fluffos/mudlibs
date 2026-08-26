/*
** shambler.c (shambling mound)
** Cyanide, 5 April 2000
*/

#include <messages.h>

inherit MONSTER;

int grow;

void create() {
    grow = 0;

    ::create();
    set("author", "cyanide");
    set("short", "a shambling mound");
    set("long", @EndLong
This creature is little more than a massive heap of rotting
vegetation, roughly humanoid shaped.
EndLong
    );
    set("id", ({ "shambling mound", "mound", "shambler" }) );
    set("race", "shambling mound");
    set("base_ac", 0);
    set("armor_class", 0);
    set_skill("Unarmed", 3, "strength");
    set("damage", ({ 2, 16 }) );
    set_verbs( ({ "crush" }) );
    set("damage_type", "crushing");
    set_name("shambler");
    set_size(9);
    set("stat", ([
      "strength" : 18,
      "constitution" : 18,
      "dexterity" : 10
    ]) );
    set("resist_type", ([
      "fire" : 0,
      "bludgeoning" : 0,
      "crushing" : 0,
      "slashing" : 50,
      "piercing" : 50,
      "cold" : 25,
    ]) );
    credit(1200);
    set("special", 4);
    set_level(14);
}

varargs int receive_damage(int dam, string type, object ob, int weap) {
    if (type=="electricity") {
	if (++grow < 6) {
	    message(MSG_COMBAT, "The shambling mound grows larger!\n",
	      environment(), TO);
	    add("level", 1);
	    add("max_hp", 21);
	    add("hit_points", 21);
	    return -8;
	}
    }

    return ::receive_damage(dam, type, ob, weap);
}


/* EOF */
