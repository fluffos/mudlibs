#include "path.h"

inherit "/room/port";

public void create()
{
  (::create());
  SetIntShort("Quay 5");
  SetIntLong(
    "This is Quay 5 of the Nightfall City harbour. Here can you start your "
    "trip to Surf City and the Halflings.\n"
    "To the south you can go to the mole and to the other quays. "
    "A timetable stands here.\n");
  SetIndoors(0);
  AddDetail(({"quay 5","quay"}),#'IntLong);
  AddDetail(({"nightfall city harbour","harbour","city harbour"}),
    "This is where you may board ships to different parts of the world.\n");
  AddDetail(({"mole","quays"}),"You see it to the south.\n");
  AddExit("south","./nf_mole3");
  // BEGONE AddShip("/d/halfling/common/obj/ship/surfship");
}
