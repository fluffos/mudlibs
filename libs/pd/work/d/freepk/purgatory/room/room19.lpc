#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : ROOMS"room20", 
                "west" : ROOMS"room18",
                "southwest" : ROOMS"room38"
  ]) );
}
