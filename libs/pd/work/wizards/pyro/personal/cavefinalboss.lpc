#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

int event_die(object);

void create() {
  ::create();
  set_name("hound");
  set_level(1001);
  set_race("microphone");
  set_gender( "male" );
  set_body_type("dog");
  set_skill("melee", 210);
  set_class("fighter");
  set_subclass("berserker");
  set_stats("strength", 1);
  set_stats("dexterity", 1);
  set_stats("charisma", 99999);
  set_stats("constitution", 1);
  set_stats("intelligence", 1);
  set_stats("wisdom", 1);
  set_overall_ac(1);
  foreach (string sk in query_all_skills()) set_skill(sk, 1);
  set_exp(0);
}
