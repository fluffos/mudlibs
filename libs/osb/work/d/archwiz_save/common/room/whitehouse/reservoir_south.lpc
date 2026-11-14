inherit "/std/room";

#include <rooms.h>
#include <moving.h>
#include "path.h"

m_n() {
  int reservoir_level;
  reservoir_level = call_other(DAMROOM,"reservoir_level");
  if (reservoir_level == 0) {
    if (!this_player()) return 0;
    this_player()->move(RESERVOIRROOM,M_GO,"north");
    }
  else {
    write("How? There is lots of water in that direction!\n");
    }
  return 1;
}

QueryIntLong() {
  int reservoir_level, reservoir_delta;
  string str;

  reservoir_level = call_other(DAMROOM,"reservoir_level");
  if (reservoir_level == 0) {
    str = "You are in a long room, to the south of which was formerly a lake. "
"However with the water level lowered, there is merely a wide stream "
"running through the center of the room.\n";
    }
  else {
    str = "You are in a long room on the south shore of a large lake, far too "
"deep and wide for crossing.\n";
    reservoir_delta = call_other(DAMROOM,"reservoir_delta");
    if (reservoir_delta < 0) {
      str += "The water level is falling.\n";
      }
    else if (reservoir_delta > 0) {
      str += "The water level is rising.\n";
      }
    }
  str += "A small passage is leaving the room to the south.\n";
  return str;
}

create() {
  ::create();
  SetIntShort("Reservoir South");
  SetIndoors(1);
  AddDetail(({"reservoir","reservoir south","long room","room","shore",
	      "south shore"}),#'IntLong);
  AddDetail(({"lake","stream","wide stream"}),"Water is in it.\n");
  AddDetail(({"water","clear water"}),"It looks clear.\n");
  AddExit("south","./atlantis_room");
  AddExit("north",#'m_n);
}
