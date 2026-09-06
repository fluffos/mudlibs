/* Cadra@NightFall 03-10-1994 */

#include "path.h"
#include <rooms.h>
#include <properties.h>

inherit "/std/room";

create() {
  ::create();
  SetIntShort("Room of Quests");
  SetIntLong(
"This is a dark dusty room, roughly hewn out of the stone. "
"The floor is carpeted with scratches: the relics from the masses of "
"quest objects which in former times lay here scattered all over. "
"To the south is a doorway.\n");
  AddDetail("doorway",
"There once have been a strong magic field. It's remains still glow there.\n");
  AddDetail(({"room of quests","questroom","room","dark room","dusty room",
  "dark dusty room"}),QueryIntLong());
  AddDetail(({"darkness"}),
"You know places which are darker.\n");
  AddDetail(({"dust"}),
"It is not that worse, but someone should really clean up here.\n");
  AddDetail(({"basalt","normal stone","stone","normal basalt"}),
"It is just normal basalt.\n");
  AddDetail(({"strong magic field","field","magic field","strong field",
  "remains"}),
"Every now and then it seems to glow.\n");
  AddDetail(({"dark glow","glow"}),
"The magic slowly seems to vanish here.\n");
  AddDetail(({"floor","ground"}),
"It is covered by a thin layer of dust which smoothes the scratches.\n");
  AddDetail(({"questitem","questitems","relics","relic",
              "questobjects", "quest objects", "objects", "items"}),
"Once upon a time, the questobjects were stored here, but nowadays just\n"
"scratches their weight caused to the floor still remain.\n");
  AddDetail(({"walls","wall","ceiling"}),
"Everything looks pretty normal.\n");
  AddDetail(({"scratch","scratches"}),
"The only remains of the heavy questobjects once stored here.\n");
  SetTPort(TPORT_NO);
  AddExit("south","./wiz_hall");
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT: "The HLP information and discussion board",
      P_LONG:
"This board carries two groups: players and players.hlp\n"
"If you have anything to discuss concerning HLP things or just want to "
"discuss it only (or before spreading it) with your fellow HLPs, feel "
"free to post on the board.\n",
      "Groups":({"players","players.hlp"})]));
}
