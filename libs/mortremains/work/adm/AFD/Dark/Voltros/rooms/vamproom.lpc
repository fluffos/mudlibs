#include "../defs.h"
inherit ROOM;

int searched;  // =1 if it has been searched!!!!!!!


void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
		set("short", "large bedroom.");
set("long", @ENDLONG
Exquisite furnishings adorn this breathtaking room.  On the northern wall,
a throne made of gold and other precious metals and stones sits.  A table 
with ivory inlays has been placed in front of the throne.  On the southern
wall, an orb rests on a shelf.  Dazzling colors dance around the room from 
the orb.  The walls are made of the same grey stone as the rest of the temple,
but in this room, the stone is clean.
ENDLONG
   );
set("fake_coins", 10000);
set("item_desc", ([
				"orb" : "A large, glass orb that emits swirling colors.\n",
				"throne" : "The throne is composed of gold, black steel, other metals and jewels.  
The throne is about 5 feet high, and it has a padded seat and back.\n",
				"table" : "This is a large, oaken table with ivory inlays.\n",
    "tile" : "The tile seems peculiar.\n",
   ]) );
set("search_desc", ([
     "orb" : "Nothing unusual can be found.\n",
					"throne" : "Nothing is unusual about the throne, but near the throne is a tile
that seems peculiar.\n",
					"table" : "Nothing unusual can be found.\n",
   ]) );


set("exits", ([
    "west" : ROOMS(swordroom),
    "east" : ROOMS(vamphall),
    ]) );

set("objects", ([
    MON(vampyre) : 1,
  ]) );
  ::create();
}

void init() {
add_action ("search_func", "search");
}

int search_func(string str) {

if(!str || str != "tile") return 0;
if(searched){ write("It looks like poor construction.\n"); return 1; }
write("You find a huge pile of coins!\n");
TP->credit((int)TO->query("fake_coins"));
searched = 1;
return 1;
}

