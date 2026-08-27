inherit "/std/container";
#include "path.h"
 
object fig1;
object fig2;

void setup() {
  set_name("shelf");
  set_long("This is one of the shelves lining the walls of Pepka's "
	 "new shop.\n");
  set_value(0);
  set_weight(10000);
  set_max_weight(10000);



if (!fig1) {
    fig1 = clone_object(ITEMS+"fig6");
    fig1->move(this_object());
  }

  if(!fig2) {
    fig2 = clone_object(ITEMS+"fig2");
    fig2->move(this_object());
  }
}
