#include <combat.h>
#include <properties.h>

inherit "/std/weapon";

create() {
  ::create();
  SetStandard(WT_STAFF,14,PSIZE_NORMAL);
  SetShort("an ancient staff");
  SetLong("You get a feeling of great power when you look at it.\n");
  SetResetQuality(100);
  SetNumberHands(2);
  SetNoGive(1);
  SetValue(800);
  SetWeight(8000);
  SetIds(({"staff","pirstaff"}));
  AddAdjective("ancient");
}

init() {
  ::init();
	   add_action("use","use");
	   add_action("drop","drop");
	   add_action("use","wave");
}

int use(string str) {
  if (str=="staff") {
    write("You try to do something magical with it, but you realize that your "
"power is much too low to use this item.\n");
    return 1;
    }
  return 0;
}

int drop(string str) {
  if (str=="staff") {
  write("The staff dissolves....\n");
  remove();
  if (this_object()) destruct(this_object());
  return 1;
  }
}
