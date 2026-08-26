// And ant in Cyanide's woods.

#include "/u/c/cyanide/debug.h"

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "a giant ant");
    set("long", wrap("A huge, hairy black ant, at least 4 feet in "+
	"length. Judging from the disproportionate size of its "+
	"razor-sharp mandibles, it's most likely a warrior."));
    set_name("giant ant");
    set("id", ({ "ant", "giant ant", "drone" }) );
    set("CLASS", "warrior");
    set("class", "fighter");
    set("stat", ([
      "strength" : 16,
      "constitution" : 15,
      "wisdom" : 3,
      "dexterity" : 15,
      "intelligence" : 1,
      "charisma" : 2,
    ]) );
    set_size(3);
    set_skill("Unarmed", 2, "strength");
    set("weapon_name", "mandibles");
    set_verbs( ({ "snap at", "bite", "chew on" }) ) ;   
    set("damage", ({ 3, 10 }) );
    set("damage_type", "slashing");
    set("base_ac", 6);
    credit(random(30)+20);
    set("race", "ant");
    set("gender", "neuter");
    set("moving", 1);
    set("speed", 3);
    set("wimpy", 10);
    set("prevent_summon", 1);
    set_level(7 + random(3));
}

void heart_beat() {
    move_around();
    ::heart_beat();
    if (!query("dying")) {
	command("eat corpse");
	command("get all");
    }
}

/* EOF */
