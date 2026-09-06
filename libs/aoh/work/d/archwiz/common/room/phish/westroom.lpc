inherit "/std/room";
#include "path.h"
#include <rooms.h>


create() {
  ::create();
  AddExit("east",PHISH("bug"));
  AddItem(PHISH("fox"),REFRESH_DESTRUCT);
  SetIntShort("Garden");
  SetIntLong(
"This is the garden of phish's castle. There are trees and bushes and singing "
"birds everywhere. The garden looks a little messy, it sure could use a good "
"gardener.\n");
  AddDetail( ({"garden"}),"There are trees and bushes everywhere.\n");
  AddDetail( ({"tree","trees","bush","bushes"}),
"They are growing everywhere. Noone seems to care about them.\n");
  AddDetail( ({"bird","birds"}),"You can only hear them.\n");
  SetIntNoise("You hear the beautiful song of a nightingale.\n");
}
