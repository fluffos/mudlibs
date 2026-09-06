#include "path.h"

inherit "/room/port";

public void create()
{
  (::create());
  SetIntShort("Quay 4");
  SetIntLong(
    "This is Quay 4 of the Nightfall City harbour. Here can you start your "
    "trip to dear old England.\n"
    "To the north you can go to the mole and to the other quays. "
    "A timetable stands here.\n");
  SetIndoors(0);
  AddDetail(({"quay 4","quay"}),#'IntLong);
  AddDetail(({"nightfall city harbour","harbour","city harbour"}),
    "You may board ships to all parts of the world in this harbour.\n");
  AddDetail(({"quays","mole"}),"Just go north.\n");
  AddExit("north", "./nf_mole2");
  // BEGONE AddShip("/d/avalon/common/ship/vikingboat");
  // BEGONE AddShip("/d/avalon/common/ship/normanboat");
}
