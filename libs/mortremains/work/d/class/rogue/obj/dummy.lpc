#include <mudlib.h>

inherit MONSTER;

void create() {
    ::create();
    seteuid(getuid()) ;
    set("short", "A Scarecrow");
    set("id", ({ "dummy", "test dummy" }) );
    set("long", "This is a dummy to test you backstab out on.\n"+
        "It will tell you how much damage you do with it.\n"+
        "You will then go into combat just like any normal\n"+
        "combat situation, type halt to stop your onslaught.\n");
    set_level(1);
    set("race", "scarecrow");
    set_name ("dummy");
    set ("gender", "neuter");
    set ("attack_strength", 1) ;
    set("damage", ({ 0 )} );
    set ("weapon_name", "head") ;
    set_verbs( ({ "swing at", "attack" }) );
    set ("stop_attack", 200);
}

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
