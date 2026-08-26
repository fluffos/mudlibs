#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "a rickety wagon");
  set("long", @ENDLONG
This wagon was put together by rotten cedarwood.  The roof is shaped 
in a half cicle.  A sign on the side marks this as the "Equipment and 
Storage" wagon for the circus.  You might want to [enter] it and find out 
what's in there.
ENDLONG
  );
  set("id", ({
    "wagon",
  }));
  set("bulk", 10000);
  set("mass", 10000);
  set_value(0);
}