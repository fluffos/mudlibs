#include <std.h>

inherit DAEMON;

int cmd_stare(string str) {
  object ob;

  if (!str || str == "") return notify_fail("Stare at what?\n");
  if (this_player()->query_race()!="dragon") return notify_fail("You cannot do that.\n");
  if (this_player()->query_ghost()) return notify_fail("You cannot do that in your immaterial state.\n");
  if (!ob=present(str, environment(this_player()))) return notify_fail("That is not here.\n");
  if (ob->query_property("no paralyze")) return notify_fail(ob->query_cap_name()+" is immune to such magic.\n");
  if (ob->query_paralyzed()) return notify_fail("They are already afraid of you.\n");
  if (ob->query_stats("wisdom") > this_player()->query_stats("wisdom") + this_player()->query_stats("strength")) return notify_fail(ob->query_cap_name()+" looks at you and laughs.\n");
  write("You stare at "+ob->query_cap_name()+" paralyzing them with fright!");
  tell_object(ob, this_player()->query_cap_name()+" stares at you paralyzing you with fright!");
  tell_room(environment(this_player()), this_player()->query_cap_name()+" stares at "+ob->query_cap_name()+" paralyzing them with fright!", ({ ob, this_player() }));
  ob->set_paralyzed(9+random(5));
  this_player()->add_mp(-(20+random(20)));
  return 1;
}
