// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "The advisors room.") ;
  set("long", @ENDLONG
This is where the King and his advisors meet to discuss issues relating
to the castle and its inhabitants.  A large table is in the center of
the room, with chairs surrounding it.  A large tapestry covers the wall
here, with the crest of the castle emblazoned upon it.
ENDLONG
  );
  set("light", 1);
  set("exits", ([
  "north" : ROOMS(throne),
  ]) );
  set("item_desc", ([
  "crest" : "It's a large gold eagle on a blue background.\n",
  "room" : "Just look around.\n",
  "chairs" : "Nothing unusual about the chairs.\n",
  "tapestry" : "The crest of the castle is emblazoned upon it.\n",
  "wall" : "A large tapestry covers the wall here.\n",
  "table" : "It has an empty pitcher on it.\n",
  "pitcher" : "It's empty.\n",
  ]) );
  set("objects", ([
  "fat advisor" : MON(fat_advisor),
  "tall advisor" : MON(tall_advisor),
  "short advisor" : MON(short_advisor),
 ]) );
  ::create();
}
