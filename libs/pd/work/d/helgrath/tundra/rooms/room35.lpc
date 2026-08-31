#include <std.h>
#include <tundra.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : ROOMS"room4", 
                "southeast" : ROOMS"room5",
                "northeast" : ROOMS"room2",
                "north" : ROOMS"room1",
                "south" : ROOMS"room6",
  ]) );
}
