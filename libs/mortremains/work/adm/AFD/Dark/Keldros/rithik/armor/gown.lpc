#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "wedding gown");
  set("long", @ENDLONG
This is an extra large wedding gown, allowing a great deal of room in
the thighs.
ENDLONG
  );
  set("id", ({
    "gown",
    "wedding gown",
    "armor",
  }));
  set("size", 6);
  set("bulk", 29);
  set("mass", 18);
  set_value(180);
  set("armor", 3);
  set_type("body");
}