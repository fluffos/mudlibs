// And ant in Cyanide's woods.

inherit MONSTER;

void create() {
    ::create();
    set("author", "cyanide");
    set("short", "a giant warrior ant");
    set("long", wrap("A huge, hairy black ant, at least 4 feet in "+
	"length. Judging from the disproportionate size of its "+
	"razor-sharp mandibles, it's most likely a warrior."));
    set("CLASS", "warrior");
    set("class", "fighter");
    set_name("giant ant");
    set("id", ({ "ant", "giant ant", "drone" }) );
    set("stat", ([
      "strength" : 20,
      "constitution" : 17,
      "wisdom" : 3,
      "dexterity" : 13,
      "intelligence" : 1,
      "charisma" : 2,
    ]) );
    set_skill("Unarmed", 3, "strength");
    set_size(4);
    set("weapon_name", "mandibles");
    set_verbs( ({ "snap at", "bite", "chew on" }) ) ;   
    set("damage", ({ 5, 15 }) );
    set("damage_type", "slashing");
    set("base_ac", 3);
    credit(random(50)+100);
    set("race", "ant");
    set("gender", "neuter");
    set("moving", 1);
    set("speed", 3);
    set("prevent_summon", 1);
    set_level(10);
}


// Here, we make it attack non-ants.

void init() {
    ::init();
    if (wizardp(TP)) return;
    if ((string)TP->query("race")!="ant")
	command("kill "+( (string *)TP->query("id") )[0] );
}

void heart_beat() {
    if (!query("dying")) {
	command("eat corpse");
	command("get all");
	move_around();
    }

    ::heart_beat();
}

/* EOF */
