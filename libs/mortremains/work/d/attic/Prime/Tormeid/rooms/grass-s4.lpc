// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Outside the castle wall.");
  set("long", @ENDLONG
You stand outside the castle wall, right next to the surrounding moat.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "north" : ROOMS(grass-s3),
    "south" : ROOMS(grass-s5),
  ]) );
  set("item_desc", ([
  "moat" :"It looks really murky.\n",
  "castle" :"You stand just outside the castle.\n",
  "wall" :"You stand just outside the castle wall.\n",
  ]) );
  ::create();
}
