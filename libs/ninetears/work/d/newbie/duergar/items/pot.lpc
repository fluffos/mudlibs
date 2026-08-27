inherit "/std/container";
#include "path.h"
 
int query_auto_load() {return 1;}

object stew;

void setup() {
  set_name("pot");
  set_long("Una gran olla acerada.  Ves vapor saliendo de ella.\n");
  set_short("olla negra");
  add_alias("olla");
  set_value(0);
  set_weight(200);
  set_max_weight(200);

  if(!stew) {
  stew = clone_object(ITEMS+"stew");
  stew->move(this_object());
  }
}
