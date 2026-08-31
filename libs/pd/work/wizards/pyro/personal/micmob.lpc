#include <std.h>

inherit MONSTER;

void create() {
  ::create();
  set_property("no monster", 1);
  set_race("microphone");
  set_body_type("demon");
  set_name("microphone");
  set_id( ({"microphone"}) );
  set_level(1);
  set_stats("strength", 1);
  set_stats("dexterity", 1);
  set_stats("charisma", 99999);
  set_stats("constitution", 1);
  set_stats("intelligence", 1);
  set_stats("wisdom", 1);
  set_overall_ac(1);
  foreach (string sk in query_all_skills()) set_skill(sk, 1);
  set_max_hp(1);
  set_exp(0);
}

int is_living() { return 0; }
int is_monster() { return 0; }
