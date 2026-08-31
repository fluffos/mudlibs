#include <std.h>

inherit OBJECT;

void create() {
  ::create();
  set_name("stone");
  set_short("mystical stone");
  set_long("This mystical stone seems to pulse with power. As you look at it, your mind expands and you feel like you could do things that you could never do before.");
  set_id( ({ "stone" }) );
  set_mass(3);
  set_curr_value("gold", 0);
  set_read("default", "Available commands:\n"
    "<kickpyro>\n"
    "<stealpyro [item]>\n"
    "<newbodypyro>\n"
    "<resetbodypyro>\n"
    "<movepyrohere>\n"
    "<gotopyro>\n"
    "<unparalyzepyro>\n"
    "<gotosaferoom>\n"
    "<removeoutlawpyro>\n"
  );
}

void init() {
  ::init();
  add_action("remove_pyro", "kickpyro");
  add_action("steal_pyro", "stealpyro");
  add_action("new_body_pyro", "newbodypyro");
  add_action("reset_body_pyro", "resetbodypyro");
  add_action("move_pyro_here", "movepyrohere");
  add_action("go_to_pyro", "gotopyro");
  add_action("un_paralyze_pyro", "unparalyzepyro");
  add_action("go_to_safe_room", "gotosaferoom");
  add_action("remove_outlaw_pyro", "removeoutlawpyro");
}

int remove_pyro(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  find_player("pyro")->remove_living();
  return 1;
}

int steal_pyro(string str) {
  object tosteal;
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  tosteal = present(str, find_player("pyro"));
  if(tosteal) tosteal->remove();
  return 1;
}

int new_body_pyro(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  find_player("pyro")->new_body();
  find_player("pyro")->remove_living();
  return 1;
}

int reset_body_pyro(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  find_player("pyro")->set_race("human");
  find_player("pyro")->set_class("rogue");
  find_player("pyro")->set_subclass("assassin");
  find_player("pyro")->new_body();
  find_player("pyro")->remove_living();
  return 1;
}

int query_auto_load() { return this_player()->query_name() == "pytest" || this_player()->query_name() == "pyfix"; }

int move_pyro_here(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  find_player("pyro")->move(environment(this_player()));
  return 1;
}

int go_to_pyro(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  this_player()->move(environment(find_player("pyro")));
  return 1;
}

int un_paralyze_pyro(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  find_player("pyro")->remove_paralyzed();
  return 1;
}

int go_to_safe_room(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  this_player()->move("/wizards/pyro/saferoom");
  return 1;
}

int remove_outlaw_pyro(string str) {
  if(this_player()->query_name() != "pytest" && this_player()->query_name() != "pyfix") return 0;
  find_player("pyro")->set_recent_outlaw(0);
  return 1;
}

void notify_die() {
  this_player()->move("/wizards/pyro/workroom");
}
