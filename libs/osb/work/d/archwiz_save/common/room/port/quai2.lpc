#include "path.h"

inherit "/room/port";

public void create()
{
  (::create());
  SetIntShort("Quay 2");
  SetIntLong(
    "This is Quay 2 of the Nightfall City harbour. Here can you start your "
    "trip to the Dark Isle.\n"
    "To the north you can go to the mole and to the other quays. "
    "A timetable stands here.\n");
// in former times you could also reach volcano from here
  SetIndoors(0);
  AddDetail(({"quay 2","quay"}),#'IntLong);
  AddDetail(({"nightfall city harbour","city harbour","harbour"}),
    "You may board ships to all parts of the world here.\n");
  AddDetail(({"mole","quays"}),"Just go north.\n");
  AddExit("north", "./nf_mole1");
  // BEGONE AddShip("/d/shadows/common/ships/blackship");
}
