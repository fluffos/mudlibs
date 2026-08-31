// 2008-08-28 Nulvect
// rewrote so it works with mobs

#include <std.h>

inherit DAEMON;

int cmd_ditch(string str) {
  object tp = this_player();
  object *fols;

  if (!str)
    return notify_fail("Ditch whom?\n");

  fols = tp->query_followers();
  if (!sizeof(fols))
    return notify_fail("Nobody is following you.\n");

  fols = filter(fols, (:
    ($1 && $1->id($2) && $1->query_following() == $3)
  :), str, tp);

  if (!sizeof(fols))
    return notify_fail("Nobody by that name is following you.\n");

  tp->remove_follower(fols[0]);

  message("info", "You ditch "+fols[0]->query_cap_name()+".", tp);
  message("info", tp->query_cap_name()+" ditches you.", fols[0]);

  return 1;
}

void help() {
  message("help",
    "Syntax: <ditch [whom]>\n\n"
    "This forces someone to stop following you.",
    this_player() );
}

