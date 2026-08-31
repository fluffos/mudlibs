
#include <std.h>

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <passive [on|off]>\n\n"
    "Turns your passive setting on or off.\n"
    "With passive on, you cannot be attacked by anybody.",
    this_player() );
}

int cmd_passive(string str) {
  object tp = this_player();

  if (str && str == "on") {
    tp->remove_property("passive");
    tp->set_property("passive", 1);
  }
  if (str && str == "off") {
    tp->remove_property("passive");
  }

  if (tp->query_property("passive"))
    message("info", "Passive: %^YELLOW%^on%^RESET%^.", tp);
  else
    message("info", "Passive: %^BOLD%^%^RED%^off%^RESET%^.", tp);

  return 1;
}

