#include "../defs.h"

inherit ROOM;
void create() {
 seteuid(getuid());
set("author","Waxer");
set("light",1);
set("short","Mr. Lyman's classroom.");
set("long", @ENDLONG
Mr. Lyman's classroom is a small room, for a classroom.
The walls are covered by papers that appear to be pages of
text.  The chalkboard lies at the front of the room is blank
suggesting that Mr. Lyman teaches mostly by word of mouth.
The desks are placed in a semi-circular pattern facing the front
of the room.
ENDLONG );

set("item_desc", ([

  "chalkboard" : "You believe this chalkboard hasn't been used in years.\n",
  "papers" : "These look like the completed lessons of children learning dwarven.\n",
  "desks" : "These are the desks of dwarven students.\n",
  "pattern" : "The pattern looks to be a way to arrange the students to learn in a
lecture environment.\n",

]) );
set("objects", ([
   MON(lchild) : 5,
   MON(mrlyman) : 1,
]) );
set("exits", ([ "south" : ROOMS(school), ]) );
::create();
}
