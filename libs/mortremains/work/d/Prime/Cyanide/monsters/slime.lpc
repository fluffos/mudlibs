
#include <mudlib.h>
inherit MONSTER ;

#define TON this_object()->query("cap_name")


void create () {

    ::create() ;
    seteuid(getuid()) ;
    set("short", "a phosphorescent slime");
    set ("long", @EndLong
EndLong
    );
    set ("id", ({ "slime", "phosphorescent slime" }) ) ;
    set("prevent_summon", 1);
    set("author", "cyanide");
    set_size(15);
    set_name ("phosphorescent slime") ;
    set ("gender", "neuter") ;
    set ("race", "slime");
    enable_commands() ;
    set_living_name("slime") ;
    set ("base_ac", 3);
    set ("armor_class", 3);
    set ("natt", 2);
    set ("damage", ({ 10, 20 }) ) ;
    set("damage_type", "acid");
    set ("weapon_name", "pseudopod") ;
    set ("CLASS", "warrior");
    set_verbs( ({ "slosh at", "swing at" }) ) ;
    set("resist_type", ([ 
      "slashing" : 5,
      "bludgeoning" : 0,
      "piercing" : 3,
    ]) );
    set("moving", 1);
    credit(random(18) + 2);
    set_level(15);
}

void init() {
    ::init();
    add_action("nodb", "deathblow");
    command("eat corpse");
    command("get all");
    /*
	if ((userp(TP)) && !(adminp(TP))) kill_ob(TP);
    */
}

void die() {
    object c1, c2, killer;
    int lvl = query_level();

    killer = query("last_attacker");
    if (!killer)  killer = previous_object();

    ::die();
    if (lvl<3) return;

    tell_room(environment(TO), "The slime splits in two!\n");
    lvl = lvl/2;

    c1 = clone_object(base_name(this_object()));
    c1->set_level(lvl);
    c1->set_size(lvl);
    c1->move(environment(TO));
    if (killer) c1->kill_ob(killer);

    c2 = clone_object(base_name(this_object()));
    c2->set_level(lvl);
    c2->set_size(lvl);
    c2->move(environment(TO));   
    if (killer) c2->kill_ob(killer);
}

int nodb (string str) {
    if (str=="slime" || str=="phosphorescent slime") {
	write("It has no head to speak of!\n");
	return 1;
    }

    return 0;
}

// I redefine heart_beat() here so 1) The heart beat
// never shuts down, and it can REALLY wander...  2) So
// The fucker can REGENERATE.

void heart_beat() {
    command("get all");
    command("eat corpse");
    continue_attack();
    unblock_attack();
    heal_up();
    move_around();

    return;
}

string query_min(string dir) {
    if (!dir || dir=="") dir = "somewhere";

    dir = TON+" flows in from the "+dir+".";
    return dir;
}

string query_mout(string dir) {
    if ( dir == "" || dir == 0 ) dir = "somewhere";
    dir = TON+" flows "+dir+".";

    return dir;
}
