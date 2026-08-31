
#include <std.h>
#include <pforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "north" : ROOMS"5",
                "west" : ROOMS"6",
                "southwest" : ROOMS"1", 
                "southeast" : ROOMS"3",
  ]) );
}
