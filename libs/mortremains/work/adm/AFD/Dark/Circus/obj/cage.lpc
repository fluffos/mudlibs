#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "A huge animal cage");
  set("long", @ENDLONG
This cage is perhaps ten feet tall,   with red cloth curtains that conceal
whatever this cage entraps.  You might be able to open the cage door 
located on the far end of the structure
ENDLONG
  );
  set("id", ({
    "cage",
  }));
  set("bulk", 10000);
  set("mass", 10000);
  set_value(0);
}