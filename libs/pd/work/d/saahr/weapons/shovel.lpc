#include <std.h>
#include <saahr.h>

inherit WEAPON;

int can_you_dig_it(string str);
void i_can_dig_it(object tp);

void init() {
  ::init();
  add_action("can_you_dig_it","dig");
}

void create() {
  ::create();
  set_id(({"shovel","small shovel","dirty shovel","small dirty shovel"}));
  set_name("shovel");
  set_short("a small, dirty shovel");
  set_long("The shovel is dull metal, full of small dents and dings. "
    "It has a wooden handle with a metal grip at the top.");
  set_weight(15);
  set_curr_value("gold", 5);
  set_wc(8);
  set_type("blunt");
}

int query_auto_load() { return 0; }

int can_you_dig_it(string str) {
  object tp=this_player();

  if (environment() != tp)
    return 0;

  if (tp->query_sp() < 10) {
    message("info","You're far too tired to dig.",tp);
    return 1;
  }

  tp->set_paralyzed(6, "You are busy digging.");;
  tp->add_sp(-10);
  message("emote","You start to dig with the shovel.",tp);
  message("emote",tp->query_cap_name()+" starts to dig with a shovel.",
    environment(tp), tp);
  call_out("i_can_dig_it", 4, tp);
  return 1;
}

void i_can_dig_it(object tp) {
  object env;
  
  if (!tp) return;

  env=environment(tp);

  tp->add_sp(-5);
  if (env->query_property("nymph_deed_room") == 1) {
    env->remove_property("nymph_deed_room");
    message("emote","You find a necklace buried in the dirt!",tp);
    message("emote",tp->query_cap_name()+" finds something buried in the dirt!",
      env, tp);
    new(ARM "nymphnecklace")->move(env);
  }
  else {
    message("emote","You find nothing in the ground.",tp);
    message("emote",tp->query_cap_name()+" finds nothing in the ground.", env, tp);
  }
  tp->set_paralyzed(0);
}
