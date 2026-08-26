#include "cm_h" 
void create() {
  seteuid(getuid());   
  make_scary();
  set("author", "Waxer");  
  set("light", 0);
  set("short", "In a mysterious cemetary.");
set("long", @ENDLONG
The cedar trees surrounding the cemetary create a canopy
of darkness which envelops the entire area.  You stand on
a narrow walkway leading through the cemetary.  Graves
of many sizes and shapes can be seen to the north, west and
east
ENDLONG
);
set("objects", ([ OBJ(grave_stone) : random(2), ]));
set("exits", ([
  "north" : ROOMS(cm_house),
  "south" : ROOMS(cm_n2),
]) );
::create();
}