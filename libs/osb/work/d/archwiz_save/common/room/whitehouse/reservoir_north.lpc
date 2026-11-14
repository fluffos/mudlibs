inherit "/std/room";

#include <rooms.h>
#include <moving.h>
#include "path.h"

QueryIntLong() {
  int reservoir_level, reservoir_delta;
  string str;

  reservoir_level = call_other(DAMROOM,"reservoir_level");
  if (reservoir_level == 0) {
    str = "You are in a long room, to the north of which was formerly a lake. "
"However with the water level lowered, there is merely a wide stream "
"running through the center of the room.\n";
    }
  else {
    str = "You are in a long room on the north shore of a large lake, far too "
"deep and wide for crossing.\n";
    reservoir_delta = call_other(DAMROOM,"reservoir_delta");
    if (reservoir_delta < 0) {
      str += "The water level is falling.\n";
      }
    else if (reservoir_delta > 0) {
      str += "The water level is rising.\n";
      }
    }
  str += "There is a path along the stream to the east or west, a steep "
"pathway climbing northwest along the edge of a chasm, and a path "
"leading into a canyon to the northeast.\n";
  return str;
}

m_s() {
  int reservoir_level;
  reservoir_level = call_other(DAMROOM,"reservoir_level");
  if (!this_player()) return 0;
  if (reservoir_level == 0) {
    this_player()->move(RESERVOIRROOM,M_GO,"south");
    }
  else {
    write("How? There is lots of water in that direction!\n");
    }
  return 1;
}

create() {
  ::create();
  SetIntShort("Reservoir North");
  SetIndoors(1);
  AddDetail(({"long room","reservoir","reservoir north","room"}),#'IntLong);
  AddDetail(({"large lake","lake","wide stream","stream"}),"There's water.\n");
  AddDetail(({"water","clear water"}),"Looks like clear water.\n");
  AddDetail(({"shore","north shore","northern shore"}),
    "You're at the northern shore.\n");
  AddDetail(({"path","pathway","steep pathway"}),
    "It'll lead you out of this room.\n");
  AddDetail(({"canyon"}),"It's to the northeast.\n");
  AddDetail(({"chasm"}),"Visit it.\n");
  AddExit("east","./dam");
  AddExit("west","./stream");
  AddExit("northwest","./chasm");
  AddExit("northeast","./canyon");
  AddExit("south",#'m_s);
}
