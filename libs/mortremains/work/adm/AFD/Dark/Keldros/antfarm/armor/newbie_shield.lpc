#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "green shield");
  set("long", @ENDLONG
This shield is made of thick oaken wood, painted forest green.
ENDLONG
  );
  set("id", ({
    "shield",
  }));
  set("bulk", 10);
  set("mass", 20);
  set_value(0);
  set("armor", 1);
}