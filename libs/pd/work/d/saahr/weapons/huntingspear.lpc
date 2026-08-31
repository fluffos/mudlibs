
#include <std.h>

inherit WEAPON;

void create() {
  ::create();
  set_name("spear");
  set_id(({"spear","hunting spear"}));
  set_short("a long hunting spear");
  set_long("The spear has a shaft about 6 feet long, "
    "with a sharpened tooth attached to the end.");
  set_weight(13);
  set_curr_value("gold", 10+random(11));
  set_wc(7);
  set_type("projectile");
}

int query_auto_load() { return 1; }
