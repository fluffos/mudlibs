
#include <std.h>
#include <saahr.h>

inherit MONSTER;

void set_trap(object to);

void create() {
  mapping inv;
  ::create();
  set_name("weimic hunter");
  set_race("weimic");
  set_body_type("weimic");
  set_gender(({"male","female","female"})[random(3)]);
  set_id(({"weimic","hunter", "weimic hunter"}));
  set_short("weimic hunter");
  set_long("A nomad of the plains, this weimic is clad in "
    "only a leather tunic that marks "+objective(query_gender())+
    "as a hunter. "+nominative(query_gender())+" has a sleek "
    "feline body with sun-bleached yellow fur, and a muscular "
    "human torso.");
  set_property("autobag", "bag");

  set_class("fighter");
  set_subclass("ranger");
  set_level(40+random(3));

  set_skill("nature", 250);
  set_skill("stealth", 100);

  set_spells(({"throw spear", "spear", "impale", "spear"}));
  set_spell_chance(33);

  inv = ([
    ARM+"weimictunic" : "wear tunic",
    OTHER+"weimicbag" : 1,
  ]);

  if (!random(2)) {
    inv += ([
      WEP+"huntingspear" : "wield spear",
    ]);
  }

  set_inventory(inv);

  if (clonep() && !random(2)) {
    call_out("set_trap", 1);
  }

}

void set_trap() {
  if (environment())
    command("trap");
}

void heart_beat() {
  object ob;
  object *corpses;
  string file, trash;
  ::heart_beat();
  if (!this_object() || !environment() || !clonep()) return;

  if (!sizeof(query_attackers())) {
    if (random(100) < 30 &&
        (ob=present("hare_kill_id",environment())) &&
        !sizeof(ob->query_attackers())) {
          message("info","The hunter quickly spears a hare.",
            environment());
          ob->die();
    }
    else if (random(100) < 30 &&
        (ob=present("fox_kill_id",environment())) &&
        !sizeof(ob->query_attackers())) {
          message("info","The hunter quickly spears a fox.",
            environment());
          ob->die();
    }
    corpses = filter(all_inventory(environment()), (: (int)$1->query_corpse() == 1 :) );
    if (sizeof(corpses)) {
      command("skin corpse");
      if (corpses[0]) corpses[0]->remove();
      if (ob = present("skin_skin_ob"))
        command("put skin in bag");
    }
  }

}

