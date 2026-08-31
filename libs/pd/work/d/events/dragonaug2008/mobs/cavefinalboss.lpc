#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

int event_die(object);

void create() {
  ::create();
  set_name("hound");
  set_id( ({ "finalboss", "hound", "great hound" }) );
  set_level(9000);
  set_short("Great Hound" );
  set_long("A gigantic hound. It is at least ten times your size.");
  set_race("hound");
  set_gender( "male" );
  set_body_type("dog");
  set_skill("melee", 210);
  set_class("fighter");
  set_subclass("berserker");
  set_stats("strength", 1);
  set_stats("dexterity", 1);
  set_stats("charisma", 900);
  set_stats("constitution", 1);
  set_stats("intelligence", 1);
  set_stats("wisdom", 1);
  set_overall_ac(1);
  foreach (string sk in query_all_skills()) set_skill(sk, 1);
  set_exp(0);
  set_die( (: event_die :) );
}

string affect_environment() { return " A massive great hound stands in the middle of the platform."; }

int event_die(object killer) {
  if(!killer) return 1;
  if(DRAG_D->query_data("canProveCourage")) {
    DRAG_D->cave_of_courage_completed(killer);
  }
  return 1;
}

int is_invincible() {
  if(!this_player() || !this_player()->is_player()) return 0;
  event_die(this_player());
  return 0;
}
