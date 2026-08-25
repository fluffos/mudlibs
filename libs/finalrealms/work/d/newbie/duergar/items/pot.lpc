inherit "/std/container";
#include "path.h"
 
int query_auto_load() {return 1;}

object stew;

void setup() {
  set_name("pot");
  set_long("A big cast-iron pot.  Steam is rising from it.\n");
  set_short("black pot");
  set_value(0);
  set_weight(200);
  set_max_weight(200);

  if(!stew) {
  stew = clone_object(ITEMS+"stew");
  stew->move(this_object());
  }
}
