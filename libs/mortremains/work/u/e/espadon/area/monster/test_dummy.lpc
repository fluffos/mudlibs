// Written by Chronos@DarkTowers to allow testing of weapons and stuff
// .. The dummy yells out how much damage was done to it... doesn't actually

#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid()) ;
set("short", "Giant Carrot");
    set("id", ({ "dummy", "test dummy" }) );
    set_level(1);
    set("race", "generic monster");
    set_name ("dummy");
    set ("gender", "neuter");
    set ("attack_strength", 1) ;
    //  set_hide_race();
    //   set_hide_condition();
    set("damage", ({ 1, 1 }) ) ;
    set ("weapon_name", "head") ;
    set_verbs( ({ "swing at", "attack" }) );
    set ("stop_attack", 200);
}

int cointinue_attack() { return 0; }

int execute_attack (int hit_mod, int dam_mod) {
    return 0;
}

int receive_damage (int i, string type) {
    string VERB, work;
    switch (i) {
    case 0: VERB = "laughs"; break;
    default: VERB = "screeches"; break;
    }
    if (!type) work = "Dummy "+ VERB + ": You just did "+i+
	" points of damage";
    else
	work = "Dummy "+ VERB + ": You just did "+i+" points of "+
	type+" damage";
    message("duhduh",
      work + ".\n", environment(), ({ this_object() }) );
    return i;
}
