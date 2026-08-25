 
#include "path.h"
inherit "/std/storeroom";
 
object button;
 
void reset()
{
   if(!button)
    button = clone_object("/obj/misc/button");
      button->move(this_object());
}
setup() {
  set_short("The storeroom");
  set_long("Big empty green.\n");
  add_exit("south",MAZE+"shop", "corridor");
  set_light(20);
}

void clean_up(int flag) {
  return 0;
}
