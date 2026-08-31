#include <std.h>
#include <pgraveyard.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 
                "east" : ROOMS"room19", 
                "west" : ROOMS"room9",
                "southeast" : ROOMS"room38"
  ]) );
}
