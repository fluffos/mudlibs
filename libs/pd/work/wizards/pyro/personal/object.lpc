
#include <std.h>
#include <id4.h>

inherit OBJECT;

string name, short, long;

void make(string newName, string newShort, string newLong) {
}

void create() {
  ::create();
  set_property("no store", 1);
  set_weight(1);
  set_curr_value("gold", 0);
}

void init_arg(mixed *args) {
  if (sizeof(args)) {
    set_owner(args[0]);
    set_color(args[1]);
    set_shortandlong(args[1]);
  }
}

mixed *query_auto_load() {
  return ({ base_name(this_object(0), ({
    owner,
    color,
    })
  });
}


