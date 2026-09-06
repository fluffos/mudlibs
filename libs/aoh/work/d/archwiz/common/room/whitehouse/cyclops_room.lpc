inherit "std/room";

#include <rooms.h>
#include "path.h"

create() {
  ::create();
  SetIntShort("Inhabitated room");
  SetIntLong(
"You are in a room which looks inhabitated. This room has an exit on the west, "
"and a staircase leading up. Set into the east wall is a wooden door.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail("lettering","You can make out some letters: "
"WITHIN THESE HALLS LIVES THE ONE EYED\n");
  AddDetail(({"inhabitated room","room"}),#'IntLong);
  AddDetail(({"exit"}),"It's to the west.\n");
  AddDetail(({"staircase","stairs"}),"The staircase leads up.\n");
  AddDetail(({"east wall","walls","wall","eastern wall"}),
    "There's a wooden door in the eastern wall.\n");
  AddExit("up","./thief_hide");
  AddExit("west","./maze12");
  AddDoor("east","./living_room","wooden door",
          "There is some gothic lettering on the door.\n",
          "cyclops key",DOOR_STATUS_LOCKED);
  AddItem(MONSTER("cyclops"),REFRESH_HOME);
}
