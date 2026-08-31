#include <std.h>

inherit OBJECT;

int cave_check();

void create() {
    ::create();
    set_id(({"eye"}));
    set_short("eye");
    set_long("A glowing eye.");
    set_weight(1);
}


int cave_check() {
  if (environment(this_player())->query_property("eyelight")) {
    environment(this_player())->set_property("light", 2);
    return 1;
  }
}
