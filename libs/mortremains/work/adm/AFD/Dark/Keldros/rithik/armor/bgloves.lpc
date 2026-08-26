#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "a pair of white lace gloves");
  set("long", @ENDLONG
They are finely made, but with  a poor quality of lace.
ENDLONG
  );
  set("id", ({
    "gloves",
    "white gloves",
    "lace gloves",
  }));
  set("size", 4);
  set("bulk", 10);
  set("mass", 8);
  set_value(150);
  set("armor", 1);
  set_type("gloves");
}