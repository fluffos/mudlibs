/* The dusty storage */

#include "path.h"
#include <rooms.h>

inherit "/std/room";

create () {
  ::create();
  SetIntShort("A small storage room");
  SetIntLong(
"You are in a small and dusty storage room. "
"You can see the shop through the opening to the east.\n"
             );
  AddExit ("east", "./shop");
  AddItem("/obj/qtyper",REFRESH_REMOVE);
}
