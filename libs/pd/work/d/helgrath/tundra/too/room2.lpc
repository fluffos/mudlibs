#include <std.h>
#include <tundratoo.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "southwest" : ROOMS"room6", 
                "southeast" : ROOMS"room7",
                "north" : ROOMS"room1"
  ]) );
}
