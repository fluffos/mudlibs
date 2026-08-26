// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Beyond the castle wall.");
  set("long", @ENDLONG
You stand next to the moat surrounding the Castle Tormeid, just outside
of the wall protecting the mighty fortress.  The grass is lush and
green here, contrasting sharply with the faded, crumbling grey mortar
of the castle wall.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "north" : ROOMS(grass-n4),
    "south" : ROOMS(grass-n2),
  ]) );
  set("item_desc", ([
  "moat" : "It looks murky and dirty.\n",
  "water" :"It looks dirty and stagnant.\n",
  "wall" : "The walls of the fortress rise high above you.\n",
  "grass" :"The grass is green and lush here.\n",
 "mortar" :"The crumbling mortar is the result of time and numerous sieges.\n",
  ]) );
  ::create();
}
