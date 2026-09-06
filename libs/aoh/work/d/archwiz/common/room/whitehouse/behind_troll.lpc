inherit "std/room";

#include <rooms.h>

create() {
  ::create();
  SetIntShort("Cellar of a white house");
  SetIntLong(
"You are in a small room with a narrow passageway leading south. "
"More Bloodstains and deep scratches (perhaps made by an axe) mark the walls.\n");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"cellar","small room","room"}),#'IntLong);
  AddDetail(({"narrow passageway","passageway"}),
    "It leads back to the south.\n");
  AddDetail(({"bloodstains","bloodstain"}),
"This blood isn't yours and you feel that this is not the worst you could say.\n");
  AddDetail(({"scratch","scratches","deep scratches","deep scratch"}),
    "Those deep scratches could be made by an axe.\n");
  AddDetail(({"walls","wall","ceiling"}),
    "Covered with bloodstains and scratches.\n");
  AddExit("south","./trollroom");
  AddItem("/d/archwiz/common/obj/cross",REFRESH_REMOVE);
}
