inherit "/std/container";
#include "path.h"
 
object bowl;
object spoon;

void setup() {
  set_name("mostrador");
  set_long("Es un mostrador de madera, gastado por el uso.  Esta lleno "
           "de platos vacios y demas cacharreria.\n");
  set_value(0);
  set_main_plural("mostradores");
  add_plural("mostradores");
  set_weight(10000);
  set_max_weight(10000);
  reset_get();

//  set_prevent_insert();


if (!spoon) {
    spoon = clone_object(ITEMS+"spoon");
    spoon->move(this_object());
  }

  if(!bowl) {
    bowl = clone_object(ITEMS+"bowl");
    bowl->move(this_object());
  }
}
