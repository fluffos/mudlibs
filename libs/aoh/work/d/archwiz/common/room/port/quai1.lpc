#include "path.h"

inherit "/room/port";

public void create()
{
  (::create());
  SetIntShort("Quay 1");
  SetIntLong(
    "This is Quay 1 of the Nightfall City harbour. Here can you start your "
    "trip to Valhalla the realm of the ancient gods.\n"
    "To the south you can go to the mole and to the other quays. "
    "A timetable stands here.\n");
  SetIndoors(0);
  AddDetail(({"quay 1","quay"}),#'IntLong);
  AddDetail(({"harbour","nightfall city harbour","city harbour"}),
    "You may board ships to all parts of the world here.\n");
  AddDetail(({"mole","quays"}),"Just go south.\n");
  AddExit("south","./nf_mole1");
  // BEGONE AddShip("/d/valhalla/common/obj/waltram");
}
