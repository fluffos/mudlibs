/* An example object to sit and lie on */

#pragma strong_types

#include <prop/item.h>

inherit "complex/item";
// basic/lie inherits basic/sit, therefore allows lying _and_ sitting
inherit "basic/lie";

void create() {
  lie::create();

  set_property(P_NOT_PORTABLE);
  set_short(0);  // Not visible
  set_long("The grass below your feet is soft and green.\n");
  set_name("meadow");
  set_id(({ "meadow", "beautiful meadow" }));
  set_allowed_prepositions(({ "on" })); // we can sit or lie _on_ the meadow
}

