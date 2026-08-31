#include <std.h>

inherit WEAPON;

void create() {
  ::create();
  set_name("dagger");
  set_id(({"dagger", "worn dagger"}));
  set_short("a worn dagger");
  set_long("The dagger is very worn out and not very sharp anymore, "
    "but still enough to do some damage.");
  set_weight(12);
  set_curr_value("gold", 13+random(5));
  set_wc(6);
  set_type("knife");
}

int query_auto_load() { return 1; }
