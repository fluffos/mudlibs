#include "../defs.h"
inherit DOORS;
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "Inside the boathouse");
  set("long", @ENDLONG
The inside of this old, creaky shed has been refurbished
into a beautiful home.  A bookcase is on the northern wall,
and 3 cots are crammed togther against the eastern wall.  
On the floor, a nice carpet has been laid.  Three doorways
lead into adjoining rooms from here.  
ENDLONG
   );
  set("item_desc", ([

   ]) );
  set("exits", ([
				"west" : ROOMS(mageroom),
				"south" : ROOMS(boathouse2),
				"north" : ROOMS(lake),
  ]) );
set("objects", ([
    MON(mapp) : 1,
  ]) );
create_door("west", "east", "It is a wooden door with an insignia on it.",
    "locked", "magekey", 25);

  ::create();

}
