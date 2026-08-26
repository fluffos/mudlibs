#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "unholy symbol");
  set("long", @ENDLONG
This is a symbol is a circle with some wierd characters inside it.
ENDLONG
  );
  set("id", ({
    "symbol",
    
  }));
  set("bulk", 10);
  set("mass", 10);
  set_value(600);
}