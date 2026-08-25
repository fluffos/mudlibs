inherit "/std/container";
#include "path.h"
 
// countertop for the newbie area food hall.

object bowl;
object spoon;

void setup() {
  set_name("counter");
  set_long("This is the counter top.  It is littered with empty cans and "
           "mess\n");
  set_value(0);
  set_weight(10000);
  set_max_weight(10000);



if (!spoon) {
    spoon = clone_object(ITEMS+"spoon");
    spoon->move(this_object());
  }

  if(!bowl) {
    bowl = clone_object(ITEMS+"bowl");
    bowl->move(this_object());
  }
}
