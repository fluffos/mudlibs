#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_listen("default", "The sounds of civilization come from the west.");
  
  set_exits(([
    "northeast" : VPROOMS "f17_7",
    "west" : VPROOMS "town15_8"
  ]));
}
