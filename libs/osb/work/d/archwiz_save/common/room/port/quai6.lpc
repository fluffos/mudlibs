#include "path.h"

inherit "/room/port";

public void create()
{
  (::create());
  SetIntShort("Quay 6");
  SetIntLong(
    "This is Quay 6 of the Nightfall City harbour. Here can you start your "
    "trip to Ireland and to the Museum Island.\n"
    "To the north you can go to the mole and to the other quays. "
    "A timetable stands here.\n");
  AddDetail(({"harbour","nightfall city harbour","city harbour"}),
"Many ships come and go. They will carry you through the world.\n");
  AddDetail(({"quay","quay 6"}),#'IntLong);
  AddDetail(({"nightfall","nightfall city","city","town","capital"}),
"Nightfall City is the capital of the world. It's harbour is the "
"most frequented in the whole world.\n");
  AddDetail(({"world","whole world"}),
"This is the world of Nightfall.\n");
  AddDetail(({"quays","other quays"}),
"There are some other quays here where you can start "
"trips to other parts of the world.\n");
  AddDetail(({"mole","wooden mole"}),
"It's to the north.\n");
  AddDetail(({"wood","old wood","weatherbeaten wood","old weatherbeaten wood"}),
"It's old and weahterbeaten.\n");
  AddExit("north", "./nf_mole3");
  // BEGONE AddShip("/d/avalon/common/ship/NFIreship");
  // BEGONE AddShip("/d/avalon/common/ship/museumship");
}
