inherit "std/room";

#include <rooms.h>
#include <properties.h>

create() {
  ::create();
  SetIntShort("Treasure Room");
  SetIntLong(
"This is a large room. A number of discarded bags, which crumble "
"at your touch, are scattered about on the floor. There is an exit "
"down a staircase.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"room","large room","treasure room"}),
    #'IntLong);
  AddDetail(({"bag","bags","discarded bag","discarded bags"}),
    "All bags you try to grab crumble to dust.\n");
  AddDetail(({"staircase","stairs"}),"The stairs lead down.\n");
  AddExit("down","./cyclops_room");
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_LONG:"The chalice is elaborately engraved.\n",
      P_SHORT:"golden chalice",
      P_IDS:({"chalice"}),
      P_ADS:({"a","the","golden"}),
      P_WEIGHT:2000,
      P_VALUE:300]) );
}
