#include "defs.h"

inherit LAND;

void reset(status arg) {

  if (arg)
  {
    ::reset(arg);
    return;
  }

  set_cost(50000);
  set_realm_name("Testing Area");
  set_lot_size("1");
  short_desc = HIY+"Player Housing System Test Room"+NORM+NORM;
  long_desc = "This is a testing room.  Fear this shit.\n";
  ::reset(arg);
}
