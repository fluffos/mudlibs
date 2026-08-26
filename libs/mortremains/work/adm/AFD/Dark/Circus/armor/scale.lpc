#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "reinforced scail mail");
  set("long", @ENDLONG
This armor is very bloody, but you can see that
it was well-constructed and has been reinforced
with metal bands.
ENDLONG
  );
  set("id", ({
    "armor",
    "scale",
    "mail",
    "scale mail",
  }));
  set("size", 5);
  set("bulk", 250);
  set("mass", 200);
  set_value(660);
  set("armor", 5);
  set_type("body");
  set("raise_stat", "strength");
  set("modifier", 1);
}