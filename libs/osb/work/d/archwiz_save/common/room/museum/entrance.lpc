#include "path.h"
#include <doors.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("C.A.R.T. museum entrance");
  SetIntLong(
"This is the entrance to the C.A.R.T. museum. You hear the wind howling "
"behind the exit door to the north. The floor is slightly vibrating. "
"The display room is to the east.\n");
  SetIndoors(1);
  AddDetail(({"ground","floor"}),
"It is made of iron and it is vibrating as the wind blows around the building.\n");
  AddDetail(({"entrance","museum","C.A.R.T. museum"}),
QueryIntLong());
  AddDetail(({"wind","howling wind"}),
"It's howling through the door.\n");
  AddDetail(({"display room","east room"}),
"Go east to see it.\n");
  AddDoor("north",CART("beach"),"wooden door",
     "An old weatherbeaten door.\n",0,DOOR_STATUS_CLOSED);
  AddExit("east","./mainroom");
}
