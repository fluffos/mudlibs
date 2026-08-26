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
and shapes can be seen to the west and east.  A tall iron
fence prevents you from going south.
ENDLONG
);
set("objects", ([ OBJ(grave_stone) : random(2), ]));
set("exits", ([
  "west" : ROOMS(cm_np5),
  "east" : ROOMS(cm_house),
]));
::create();
}