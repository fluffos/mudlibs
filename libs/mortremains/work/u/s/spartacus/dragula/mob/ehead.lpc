/*
**THE ELECTRIC HEAD
**ehead.c
**Spartacus, May 1, 2000
**This was hacked from the rampager.c file.
*/

inherit MONSTER;

void create() {
    ::create();
    set("author", "spartacus");
   set("prevent_summon", 1);
    set("short", "The Electric Head");
    set("long", @EndLong
The Electric Head is the biggest, nastiest,
ugliest, most grotesque thing that you have
ever laid your puny little eyes on in
you life.  It stands a whopping 100 feet tall, and
reeks of death, decay, and anarchy.  Needless to
say, it could (and will if given the chance) kick
your puny little ass from kingdom come to timbuktu.
EndLong
    );
    set("id", ({ "head" , "electric" , "death" }) );
    set("prevent_summon", 1);
    set("base_ac", -4);
    set("armor_class", -4);
    set_skill("Unarmed", 3, "strength");
    set("damage", ({ 2, 12 }) );
    set_verbs( ({ "mutilates" }) );
    set("weapon_name", "fists");
    set("damage_type", "electricity");
    set_name("electric head");
    set("stat/constitution", 20);
    set_size(100);
    set("stat", ([
      "strength" : 18,
      "constitution" : 18,
      "dexterity" : 20
    ]) );
    set("resist_type", ([
      "slashing" : 40,
      "piercing" : 40,
      "bludgeoning" : 50
    ]) );
    set("magic_resist", 25);
    credit(10000);
    set("special", 4);
    set_level(70);
}

// This function is called whenever the monster hit with
// its claws. .
int hit_func( object targ, int damage) {

    if (!random(2)) {
	tell_object(targ, "The Electric Head shoot electricity from it's fists!\n");
	targ->receive_damage(200, "electricity");
    }

    // The func returns the damage sent to it. This allows the value
    // to be changed during run time.

    return damage;
}

/* EOF */
