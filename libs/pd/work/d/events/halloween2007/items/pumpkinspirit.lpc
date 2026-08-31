
#include <std.h>
#include <h2k7.h>

inherit OBJECT;

int no_eat(string str);
int do_break(string str);
void move_me();

void create() {
  ::create();
  set_heart_beat(2);
  set_name("pumpkin");
  set_id( ({ "pumpkin", "round pumpkin"}) );
  set_short("a round %^ORANGE%^pumpkin%^RESET%^");
  set_long("This pumpkin is extremely round, and the lightest push sends it "
    "rolling. The stem is still soft and pliable and the ridged skin is a "
    "deep orange.");
  set_weight(4);
  set_property("magic item", ({ "break", "crack" }) );
  set_no_clean(1);
}

void heart_beat() {
  object to = this_object();
  object env = environment(to);
  object go;
  string *rooms;

  if (!env) return;
  if (!env->is_room()) return;
  if (random(2000) >= 1100) return;

  move_me();
}

void init() {
  ::init();
  add_action("no_eat", "eat");
  add_action("do_break", ({ "break", "crack" }) );
  //if (random(2000) < 1800) move_me();
}

void move_me() {
  object go;
  object to;
  string *rooms;

  if (!environment()->is_room()) return;
  to = this_object();
  rooms = environment(to)->query_destinations();
  rooms = filter(rooms, (: !strsrch($1, H2K7ROOMS) :) );
  if (sizeof(rooms))
    go = load_object(rooms[random(sizeof(rooms))]);
  if (objectp(go))
    to->move(go);
}

int no_eat(string str) {
  object to = this_object();
  object env = environment(to);

  if (!env || !str || present(str, env) != to) return 0;

  message("info", "As you try to bite into the pumpkin, "
    "a light glows around it.", this_player() );
  return 1;
}

int do_break(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment(tp);
  object spirit;

  if (!tp || !to || !env || !str ||
     (present(str, tp) != to && present(str, env) != to) ) return 0;

  message("info", "You break open the pumpkin.", tp);
  message("info", tp->query_cap_name()+" breaks open the pumpkin.", env, tp);
  message("info", "%^BOLD%^%^WHITE%^A spirit flies up out of the pumpkin!", env);

  spirit = new(H2K7MOBS"trappedspirit");
  spirit->move(env);
  spirit->finish_quest(tp);

  call_out("remove_me", 0);

  return 1;

}

void remove_me() { this_object()->remove(); }

