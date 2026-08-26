#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "silver coin");
  set("long", @ENDLONG
This is a silver coin with the 'Traeu' family seal.
ENDLONG
  );
  set("id", ({
    "coin",
   "silver_coin",
  }));
  set("bulk", 1);
  set("mass", 1);
  set_value(150);
}
