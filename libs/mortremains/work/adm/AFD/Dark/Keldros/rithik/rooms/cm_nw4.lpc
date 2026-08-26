#include "cm_h"

void create() {
  seteuid(getuid());
  make_scary();
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In a mysterious cemetary.");
set("long", @ENDLONG
The cedar trees surrounding the cemetary create a canopy
of darkness which envelops the entire area.  You stand
on a walkway through the cemetary.  Graves of many sizes
and shapes can be seen all around you.
ENDLONG
);
set("objects", ([ OBJ(grave_stone) : 1, ]));
set("exits", ([
  "south" : ROOMS(cm_nw3),
  "east" : ROOMS(cm_np6.c),
]) );

::create();
}