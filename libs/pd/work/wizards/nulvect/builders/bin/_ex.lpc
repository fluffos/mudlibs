//by Rull

#include <std.h>

inherit DAEMON;

int not_invis(string ex, object env) { return !(env->invis_exit(ex)); }

int cmd_ex(string str) {
  string *ex;
  object tp=this_player();
  string exout;

  object env=environment(this_player());

  if (!env) { return notify_fail("You have no environment, this is a bug."); }

  ex=env->query_exits();
  ex=filter(ex, "not_invis", this_object(), env);
  if (!(sizeof(ex))) { ex = ({"none"}); }
  exout=implode(ex, ", ");
  
  exout=replace_string(exout, "southeast", "se", 1);
  exout=replace_string(exout, "northeast", "ne", 1);
  exout=replace_string(exout, "southwest", "sw", 1);
  exout=replace_string(exout, "northwest", "nw", 1);
  exout=replace_string(exout, "north", "n", 1);
  exout=replace_string(exout, "south", "s", 1);
  exout=replace_string(exout, "west", "w", 1);
  exout=replace_string(exout, "east", "e", 1);
  exout=replace_string(exout, "up", "u", 1);
  exout=replace_string(exout, "down", "d", 1);

  message("exits","%^GREEN%^Exits: "+exout+"%^RESET%^.",tp);
  return 1;
}

