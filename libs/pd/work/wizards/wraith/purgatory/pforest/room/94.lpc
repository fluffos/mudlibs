#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "north" : ROOMS"97",
                "south" : ROOMS"92",
                "west" : ROOMS"98",
                "southwest" : ROOMS"93",
                "southeast" : ROOMS"95",
                "northeast" : ROOMS"96",
  ]) );
}
