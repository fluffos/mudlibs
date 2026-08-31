#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : ROOMS"room21", 
                "west" : ROOMS"room19",
                "southeast" : ROOMS"room43",
  ]) );
}
