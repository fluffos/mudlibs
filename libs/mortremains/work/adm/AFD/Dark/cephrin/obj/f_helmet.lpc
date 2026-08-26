
#include <mudlib.h>
#include "../defs.h"

inherit OBJECT;

void create() {
  seteuid(getuid());
  set("short", "a cracked helmet");
  set("long", @ENDLONG
This should never be seen.
ENDLONG
  );
  set("id", ({
    "helmet",
  }));
}