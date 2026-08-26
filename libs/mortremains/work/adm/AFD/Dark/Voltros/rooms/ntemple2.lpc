#include <mudlib.h>
#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "A pew-lined room.");
set("long", @ENDLONG
This is an old worship place.  It seems that this room has been turned into
into a meeting place of some sort.  Maps lie strew about on the front
pew;  The altar and podium have been pulverized into tiny peices.  To
the north, you can see a bright glow.
ENDLONG
);
  set("item_desc", ([
   "pews" : "These are standard hard wood pews.  They are covered with grease\n and grime.",
   "altar" : "The altar is in tiny little peices all over the place.\n",
   "podium" : "It seems to have met the same fate as the altar.\n",
   "maps" : "They are maps of the surrounding areas.\n",
   "peices" : "Little peices of wood lie about the room.\n",
		"glow" : "To the north, a bright white light pierces the evil shroud around the temple.\n", 
   ]) );
  set("exits", ([
    "south" : ROOMS(ntemple1),
    "north" : ROOMS(holy),
  ]) );
  set("objects", ([
   MON(darknight) : 1,
   MON(darknight2) : 1,
   MON(delnor) : 1,
   MON(darkguard) : 1,
   MON(phoscaff) : 1,
   MON(darkguard2) : 1,
]));

  ::create();
}
