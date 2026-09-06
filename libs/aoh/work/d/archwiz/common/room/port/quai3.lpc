#include "path.h"

inherit "/room/port";

public void create()
{
  (::create());
  SetIntShort("Quay 3");
  SetIntLong(
    "This is Quay 3 of the Nightfall City harbour. Here can you start your "
    "trip to the Orient and Port Atlinten.\n"
    "To the south you can go to the mole and to the other quays. "
    "A timetable stands here.\n");
  SetIndoors(0);
  AddDetail(({"quay 3","quay"}),#'IntLong);
  AddDetail(({"nightfall city harbour","city harbour","harbour"}),
    "You may board ships oto all parts of the world here.\n");
  AddDetail(({"quais","mole"}),"Just go south.\n");
  AddExit("south","./nf_mole2");
  // BEGONE AddShip("/d/atlantis/common/ships/NFship");
  // BEGONE AddShip("/d/orient/common/ships/dhau");
}
