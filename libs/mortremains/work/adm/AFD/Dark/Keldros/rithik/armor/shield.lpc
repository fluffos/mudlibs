
#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "a steele shield");
  set("long", @ENDLONG
This shield has been fashioned out of tough steele, hammered
to perfection.  The handstrap is a fine, black leather.
ENDLONG
  );
  set("id", ({
    "shield",
    "steele shield",
  }));
  set("bulk", 20);
  set("mass", 40);
  set_value(360);
  set("armor", 3);
  set_type("shield");
}
