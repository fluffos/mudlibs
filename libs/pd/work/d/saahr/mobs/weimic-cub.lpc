
#include <std.h>
#include <saahr.h>

inherit MONSTER;

int adult;

void create() {
  ::create();
  set_name("weimic cub");
  set_race("weimic");
  set_body_type("weimic");
  set_gender(({"male","female","female"})[random(3)]);
  set_id(({"weimic","cub","weimic cub"}));
  set_short("weimic cub");
  set_long("A nomad of the plains, this cub is out learning to hunt. "+
    nominative(query_gender())+" appears well-muscled in both human and "
    "feline portions and eagerly follows "+possessive(query_gender())+" elders.");

  set_class("fighter");
  set_subclass("warrior");
  set_level(27+random(2));
  
  set_spells(({"impale"}));
  set_spell_chance(35);

  if (!random(2)) {
    set_inventory( ([
      WEP+"huntingspear" : "wield spear",
    ]) );
  }

  adult = 0;
}

void heart_beat() {
  object env;
  ::heart_beat();
  if (!this_object()) return;

  env = environment();

  if (env && !adult) {
    adult = 1;
    if (!present("weimic hunter",env))
      new(MOBS "weimic-adult")->move(env);
  }
}

