/* made by Sique using RoomMaker V0.992 (c) Sique 2/1993 */

#include "path.h"
#include <rooms.h>
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Main Street");
  SetIntLong(
"A section of Main Street going west-east. The street opens west to "
"Central Plaza. To the south lies the Nightfall Central Airport and "
"to the north you can see a monastry next to a white house.\n"
    );
  AddDetail("section","You are in the business district of Nightfall City.\n");
  AddDetail(({"floor","ground"}),"It is just a normal street.\n");
  AddDetail(({"city","nightfall city","capital","town"}),
  "Nightfall city is the capital of the world.\n");
  AddDetail(({"street","main street"}),
  "You walk along the main street. There is an airport to the south and you can "
"see a white house to the north.\n");
  AddDetail(({"airport","nightfall central airport","nightfall city airport"}),
  "You see dragons come and go. They carry small gondolas.\n");
  AddDetail(({"dragon","dragons"}),
  "Those are the dragons of the dragon airways.\n");
  AddDetail(({"gondala","gondolas"}),
  "The gondolas are fasten to the dagons.\n");
  AddDetail(({"plaza","central plaza"}),
  "It is to the west.\n");
  AddDetail("monastry","It is to the northeast.\n");
  AddExit("north","./shouse");
  AddExit("south","./airport1");
  AddExit("west","./vill_green");
  AddExit("east","./vill_road1");
//  AddItem(MONSTER("nervi"),REFRESH_DESTRUCT);
// Disabled after some kind of wizconf. Noone liked him. [Loco 04Nov95]
  SetIndoors(0);
}
