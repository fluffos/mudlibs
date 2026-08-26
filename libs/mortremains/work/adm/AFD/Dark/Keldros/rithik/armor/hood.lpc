#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "the black hood of an executioner");
  set("long", @ENDLONG
This hood is made of black silk.  It covers the
entire face except for two holes for the eyes.
ENDLONG
  );
  set("id", ({
    "hood",
    "black hood",
  }));
  set("size", 4);
  set("bulk", 10);
  set("mass", 8);
  set_value(855);
  set("armor", 1);
  set_type("helmet");
}