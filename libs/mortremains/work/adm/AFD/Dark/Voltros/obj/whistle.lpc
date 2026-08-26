#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "a toy whistle");
  set("long", @ENDLONG
This is a green, toy whistle.
ENDLONG
  );
  set("id", ({
    "necklace",
    
  }));
  set("bulk", 1);
  set("mass", 1);
  set_value(200);
}