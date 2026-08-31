#include <std.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <unwield [weapon]>\n"
    "\n"
    "This command will release a weapon from your hand so that you "
    "no longer use it for combat.",
    this_player() );
}

int cmd_unwield(string str) {
  object tp = this_player();
  object env = environment(tp);
  object wep;
  mixed unwield;

  if (!str)
    return notify_fail("Unwield what?");

  wep = present(str, tp);

  if (!wep)
    return notify_fail("You do not have a \""+str+"\".");

  if (!wep->query_wielded())
    return notify_fail("You are not wielding that!");

  tp->set_disable(1);

  wep->unequip();

  return 1;
}

