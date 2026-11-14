/* made by RoomMaker V0.991 (c) Sique 2/1993 */

#include "path.h"
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Pub Street");
  SetIntLong(
"This is a gloomy alley. You won't stay here too long, if you have "
"valuables with you. To the south the alley widens into a small yard, "
"and the sun shines on white buildings to the north.\n"
"To the west some workers are busy changing the interior of an empty building. "
"To the east the Culture Center of Nightfall City has opened.\n"
    );
  AddExit("north","./sunalley2");
  AddExit("south","./yard");
  AddExit("west","./haircutter");
  AddExit("east",CULTURE("culture"));
  SetIndoors(0);
}
