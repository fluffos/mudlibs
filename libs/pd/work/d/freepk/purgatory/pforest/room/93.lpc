#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "north" : ROOMS"98",
                "south" : ROOMS"85",
                "east" : ROOMS"95",
                "west" : ROOMS"84",
                "northwest" : ROOMS"99",
                "southeast" : ROOMS"92",
                "northeast" : ROOMS"94",
  ]) );
}
