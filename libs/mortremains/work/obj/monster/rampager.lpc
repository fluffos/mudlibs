/*
** rampager.c
** Cyanide, Mar 21, 2000
** 
** This is an effective example of how to use a "hit_func"
** in a monster.
*/

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "a rampager");
    set("long", @EndLong
A rampager is a huge, six-legged creature with gray scales 
covering its whole body. The four rear legs are large round pads,
while the two front legs have claws as long as daggers. The face
is out of a nightmare, with long dirty fangs and glowing red 
eyes.
EndLong
    );
    set("id", ({ "rampager" }) );
    set("base_ac", -4);
    set("armor_class", -4);
    set("damage", ({ 2, 12 }) );
    set_verbs( ({ "bite" }) );
    set("weapon_name", "claws");
    set("damage_type", "slashing");
    set_name("rampager");
    set("stat/constitution", 12);
    set_size(40);
    set("stat", ([
      "strength" : 18,
      "constitution" : 18,
      "dexterity" : 10
    ]) );
    set("resist_type", ([
      "slashing" : 40,
      "piercing" : 40,
      "bludgeoning" : 50
    ]) );
    set("magic_resist", 25);
    credit(1200);
    set("special", 4);
    set_level(14);
}

// This function is called whenever the monster hit with
// its claws. .
int hit_func( object targ, int damage) {

    if (!random(2)) {
	tell_object(targ, "The rampager's claws secrete corrosive acid!\n");
	targ->receive_damage(20, "acid");
    }

    // The func returns the damage sent to it. This allows the value
    // to be changed during run time.

    return damage;
}

/* EOF */
