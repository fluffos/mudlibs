#include <std.h>
#include <dragonevent.h>

inherit MONSTER;

int idlerounds;

void create() {
  ::create();
  set_property("no corpse", 1);
  set_name("bee");
  set_short("a %^RESET%^%^ORANGE%^b%^BOLD%^%^BLACK%^e%^RESET%^%^ORANGE%^e%^RESET%^");
  set_long(
    "%^YELLOW%^       __%^RESET%^%^ORANGE%^_%^YELLOW%^__\n"
    "    __/     \\\n"
    "   /. \\ `%^RESET%^%^ORANGE%^,%^YELLOW%^,  |%^BLACK%^___%^YELLOW%^\n"
    "   \\__/      |\n"
    "      \\__%^RESET%^%^ORANGE%^_%^YELLOW%^__/\n"
  );
  set_level(8 + random(4));
  set_race("bee");
  set_body_type("insctwgd");
  idlerounds = 0;
}

void heart_beat() {
  object env = environment();
  string *exits;
  ::heart_beat();
  if(!this_object()) return;
  if(!env) return;
  exits = env->query_exits();
  foreach(object ob in all_inventory(environment(this_object())))
    if(ob->is_player()) {
      if(random(40) == 5)
        force_me("kill "+ob->query_name());
      idlerounds = 0;
      return;
    }

  //find a player to move to.
  idlerounds++;
  if(idlerounds >= 30) this_object()->remove();
  if (sizeof(exits))
    force_me(exits[random(sizeof(exits))]);
}
