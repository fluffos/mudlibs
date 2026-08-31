
#include <std.h>
#include <dragonevent.h>

// dir to pick a random room from, must end with /
#define RANDOM_DIR "/d/tirunmts/rooms/"

inherit MONSTER;

int check_die(object tp);
void go_to_random_room();

void create() {
  ::create();
  set_name("ogre");
  set_id( ({ "large ogre", "gem ogre" }) );
  set_short("a large ogre");
  set_long("This ogre is quite tall and very muscular. He seems to be "
    "trying to get somewhere.");
  set_race("ogre");
  set_body_type("human");
  set_class("rogue");
  set_subclass("thug");
  set_level(35);
  set_alignment(-750);
  set_spell_chance(70);
  set_spells( ({ "clobber", "smash", "stomp", "dirt", "dodge", "clobber" }) );
  set_stats("strength", 80);
  set_stats("constitution", 80);
  set_skill("melee", 200);
  set_skill("murder", 200);
  set_max_hp(9000);
  set_hp(query_max_hp());
  set_speed(2);
  set_moving(1);
  set_aggressive("choke_him");
  set_die( (: check_die :) );
  if (!sizeof(children(DRAG_ITEMS+"blackgem")))
    load_object(DRAG_ITEMS+"blackgem")->move(this_object());
}

void choke_him() {
  object tp = this_player();
  if (tp->is_player() && tp->query_level() >= 20 && !tp->query_invis())
    call_out("command", 2, "choke "+tp->query_name());
}

int check_die(object tp) {
  if (!tp) tp = query_current_attacker();
  if (!tp || !tp->is_player() || DRAG_D->query_data("cankillgemogre") != 1)
    return 1;

  DRAG_D->set_data("winnergemogrekilled", tp->query_name());
  DRAG_D->set_data("cankillgemogre", 0);
  DRAG_D->set_data("canloadgemogre", 0);
  message("magic", "You feel a magical force surround you.", tp);
  message("magic", "A magical force surrounds "+tp->query_cap_name()+".",
    environment(tp), tp);

  tp->add_exp(500000);
  foreach (string stat in ({ "strength", "dexterity", "constitution" }) )
    tp->set_stats(stat, tp->query_base_stats(stat)+2);

  message("magic", "%^BOLD%^%^ORANGE%^You feel stronger "
    "and faster.%^RESET%^", tp);

  return 1;
}

int killme() { return ::remove(); }

int remove() {
  if (query_hp() < 1)
    return ::remove();
  go_to_random_room();
  return 0;
}

void go_to_random_room() {
  string *rooms;
  string myroom;
  rooms = get_dir(RANDOM_DIR+"*.c");
  do {
    myroom = rooms[random(sizeof(rooms))];
    myroom = RANDOM_DIR+myroom;
  } while (environment() && myroom == file_name(environment())+".c");
  move(myroom);
  if (DRAG_D->query_data("testing"))
    message("info", "%% GemOgre moved to "+myroom+".", DRAG_D);
}

