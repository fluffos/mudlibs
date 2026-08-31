//      /cmds/mortal/_partyrange.c
//      Nightshade

#include <std.h>
#include <daemons.h>

inherit DAEMON;

int cmd_partyrange(string str) {
    object *users = users();
    object tp = this_player();

    message("system",
      "   %^BOLD%^People in party range\n"
      "%^RESET%^%^CYAN%^============================%^RESET%^", tp);
    foreach (object person in users)
      if (!wizardp(person) && person != tp &&
          absolute_value(person->query_level() - tp->query_level()) <= 5)
            message("system","     "+person->query_cap_name(),tp);
    return 1;
}

void help() {
    message("system",
      "Syntax: <partyrange>\n"
      "Lists everyone within your party range.", this_player());
}
