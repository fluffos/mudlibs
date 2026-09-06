/* made by Sique using RoomMaker V0.99.3 (c) Sique 2/1993 */

#include "path.h"
#include <rooms.h>
inherit "/std/room";

create() {
  ::create();
  SetIntShort("Business District");
  SetIntLong(
"This is the Business District, part of Main Street that continues "
"west towards city center and east towards the sea shore. "
"To the north is a general store, to the south is the famous adventurers "
"guild.\n"
    );
  AddExit("north","./shop");
  AddExit("west","./vill_road1");
  AddExit("east","./vill_shore");
// That room does not exist... Sonic, 19-May-1997
//  AddExit("south","/p/guilds/adventurers/room/nf-city");
  AddItem(MONSTER("harry"),REFRESH_HOME);
  SetIndoors(0);
}
