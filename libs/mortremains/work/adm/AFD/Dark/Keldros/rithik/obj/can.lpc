#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "a can of paint");
  set("long", @ENDLONG
This is a can of blue paint, tainted with other primary colors.
ENDLONG
  );
  set("id", ({
    "can",
    "paint",
    "paint can",
    
  }));
  set("bulk", 10);
  set("mass", 5);
  set_value(50);
 
}