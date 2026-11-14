#include "path.h"

inherit "std/room";

create() {
  ::create();
  SetIntShort("Ruins of the sanctum");
  SetIntLong(
"A long time ago, this was the inner sanctum of the psionics' guild. "
"You can still see that this must have been a place of rare power, "
"and you feel that many mighty psionics have roamed this now abandoned "
"building. East of here is an open place, you can hear water gurgling "
"there. To the south you see a strange opening in the wall.\n"
            );
  AddDetail(({"place","open place","east"}),
"You can see a small fountain there.\n"
           );
  AddDetail(({"opening","strange opening"}),
"It is a round opening in the wall, about six feet high. "
"The fringe of this opening is covered with indecypherable symbols.\n"
           );
  AddDetail("symbols","They look like they are from an ancient language.\n");
  AddExit("north", "./psi_ruins1");
  AddExit("south", "./psi_ruins3");
  AddExit("east",  "./psi_ruins4");
  SetIndoors(0);
  SetIntNoise("You here the gurgling of a fountain.\n");
}
