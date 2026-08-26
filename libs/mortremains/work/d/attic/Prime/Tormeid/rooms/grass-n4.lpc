// This room has a portal to the Demon temple, an area that Chronos
// was planning on making, but probably won't since he doesn't like 
// to make half-assed areas.  If he returns, this portal will eventually
// go somewhere, but until then.. let the players speculate on what it is.
// It'll give them something to talk about.  :)
// - Chronos.
// Coded by Chronos.
#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());
  set("short", "Beside the moat.");
  set("long", @ENDLONG
You stand beside the moat surrounding the castle.  Crumbled mortar and 
stone litter the lush grass here, suggesting that this part of the 
castle was at one time under siege, perhaps even damaged.  You notice
ancient, but still noticable scorch marks on the wall higher up.
The base of the northwest tower is directly north of here.
ENDLONG
  );
  set("light", 1);
  set_outside(); // default to weather zone A
  set("exits", ([
    "north" : ROOMS(grass-n5),
    "south" : ROOMS(grass-n3),
  ]) );
  set("item_desc", ([
  "wall" : "The wall rises to the east.  High above you, you notice numerous scorch marks covering the wall.\n",
  "moat" : "It's just to the west.\n",
  "castle" :"You stand just outside the castle walls.\n",
  "grass" : "The grass is littered with crumbling mortar.\n",
  "scorch marks" : "There seems to have been numerous explosions here.\n",
  "marks" :"There seems to have been numerous explosions here.\n",
   "base" :"It's the base of the tower.\n",
 "stone" :"The stone and mortar are crumbling from the wall.\n",
  "mortar" : "The stone and mortar are crumbling from the wall.\n",
   "tower" : "The tower rises high up into the air before you.\n",
  ]) );
  set("objects", ([
  "#PORTAL#" : OBJ(demon_portal),
  ]) );
  set("exit_msg", ([
  ]) );
  ::create();
}
