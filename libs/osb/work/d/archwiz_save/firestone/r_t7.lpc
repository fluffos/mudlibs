#include <rooms.h>
#include <properties.h>
inherit "/std/room";

create() {
  ::create();
  SetIntShort("In a corridor");
  SetIntLong("You are in a corridor.\n");
  SetIndoors(1);
  AddExit("north","./r_t6");
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT: "a communicator",
      P_LONG: "You see a nameplate with the inscription: 'J. T. Kirk.\n",
      P_IDS: ({"communicator"}),
      P_WEIGHT: 800,
      P_VALUE: 20,
      P_NOSELL: 1]));
}
