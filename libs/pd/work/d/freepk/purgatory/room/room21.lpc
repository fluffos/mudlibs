#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : ROOMS"room22", 
                "west" : ROOMS"room20",
                "southwest" : ROOMS"room43"
  ]) );
}
