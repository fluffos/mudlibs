#include <mudlib.h>

#include "../defs.h"


inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Waxer");
  set("light", 1);
  set("short", "A small Church.");

set("long", @ENDLONG
This is a small church.  Judging by the symbol above the door, the
congregation of this chruch worships Dryox, dwarven god of rebirth.
The church is crafted from wood and stone.  The pews are dark
cedarwood, aligned in two rows of fifteen pews each.  The walls
have white decorations and the altar has been donned with
flowers of all colors, seeming to suggest that maybe  a wedding
is going to take place today.
ENDLONG
);
  set("item_desc", ([
    "symbol" : "The symbol is a double-bladed axe broken through the
center of the blade.\n",
    "buildings" : ".\n",
    "decorations" : "These are customary decorations for a wedding in this
region.\n",
   "pews" : "These are standard hard wood pews.",
   "altar" : "The altar has been covered with white and blue roses.",
   "walls" : "They have plentiful decorations adorning them.\n",
   "flowers" : "Flowers are a symbol of growth and prosperity among this group of dwarves.\n",
   "cedarwood" : "Most everything of good construction in this town is built of the wood
from cedar trees.\n"
   ]) );

  set("smell", ([
    "default" : "You can make out the sent of incense burning, apparrently
in celebration of the wedding.\n", ]) );

  set("exits", ([
    "north" : ROOMS(inter3),
    "west" : ROOMS(inter),
  ]) );
  set("objects", ([ 
   MON(bride) : 1,
   MON(groom) : 1,
   MON(priest) : 1,
   MON(altarboy) : 1,
   MON(witness) : 1,
   MON(rbear) : 1,
]));

  ::create();
}
