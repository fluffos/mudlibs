#include <mudlib.h>

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "A set of golden knitting needles");
  set("long", @ENDLONG
This is a set of knitting needles, golden in color.
ENDLONG
  );
  set("id", ({
    "set",
    "needle",
    "needles",
     "set of needles",
  }));
  set("bulk", 70);
  set("mass", 70);
  set_value(110);
}