#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "decayed scale mail");
  set("long", @ENDLONG
This armor has decayed from years of no use
or cleaning.  Patches of grey mold fill some
of the joints.
ENDLONG
  );
  set("id", ({
    "scale mail",
    "scale",
    "mail",
    "armor",
  }));
  set("size", 4);
  set("bulk", 8);
  set("mass", 10);
  set_value(380);
  set("armor", 4);
  set_type("body");
}