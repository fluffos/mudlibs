#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "a bent copper ring");
  set("long", @ENDLONG
This is a nearly worthless piece of jewelry.
The bend in it has restricted its size.
ENDLONG
  );
  set("id", ({
    "ring",
    "copper ring",
  }));
  set("size", 2);
  set("bulk", 10);
  set("mass", 20);
  set_value(12);
  set("armor", 1);
  set("type", "ring");
}