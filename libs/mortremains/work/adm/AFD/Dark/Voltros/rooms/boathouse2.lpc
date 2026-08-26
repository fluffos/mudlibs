#include "../defs.h"
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
  set("short", "Inside the boathouse");
  set("long", @ENDLONG
This is the bedroom of the apprentice mages.  Three cots
line the south wall, and a bookcase is placed apon the
west wall. A table has been push near the east wall.
ENDLONG
   );
  set("item_desc", ([

   ]) );
  set("exits", ([
				"north" : ROOMS(boathouse),
  ]) );
set("objects", ([
    MON(mapp) : 2,
  ]) );
  ::create();

}
