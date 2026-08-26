#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "a tattered leather cloak");
  set("long", @ENDLONG
This cloak once was made of finely fashioned
leather, it is now tattered and nearly worthless.
ENDLONG
  );
  set("id", ({
    "cloak",
    "leather cloak",
    "tattered cloak",
  }));
  set("size", -1);
  set("bulk", 10);
  set("mass", 20);
  set_value(42);
  set("armor", 1);
  set("type", "cloak");
}