#include <std.h>
inherit DAEMON;

int cmd_zone() {
  environment(this_player())->show_zone(this_player());

  return 1;
}

void help() {
    write("Syntax: <zone>\n"
      "This command lets you know if you are in a pk, lawful, or nopk zone."
    );
}

