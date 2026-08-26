#include <mudlib.h>

inherit ARMOR;

void create() {
  seteuid(getuid());
  set("short", "a bloody bandage");
  set("long", @ENDLONG
This is a cloth bandage, it has been bloodied by
the open wound of some creature.
ENDLONG
  );
  set("id", ({
    "bandage",
  }));
  set("bulk", 10);
  set("mass", 20);
  set_value(35);
  set("armor", 1);
  set("type", "helmet");
}