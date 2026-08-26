#include "../defs.h"

inherit ROOM;
inherit DOORS;
void create() {
  seteuid(getuid());
  set("author", "Gendor");
  set("light", 1);
		set("short", "lighted hallway.");
set("long", @ENDLONG
This long hallway extends to the east and the west.  At the far west side,
you can hear some music of some sort playing.
ENDLONG
   );
set("exits", ([
    "west" : ROOMS(vamproom),
    "east" : ROOMS(foyer),
    ]) );
create_door("east", "west", "It's a black iron door.",
    "locked", "bkey", 45);
  ::create();
}

