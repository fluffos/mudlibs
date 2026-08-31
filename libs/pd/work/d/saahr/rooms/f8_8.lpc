#include <std.h>
#include <saahr.h>

inherit VIRTUALROOM;

void create() {
  set_server(VFSERVER);
  ::create();

  set_items( (query_items() || ([])) + ([
    "river" : "The river looks kind of shallow to the east, it might be possible to wade through.",
    "east" : "The back of a house can be seen across the river.",
  ]) );
  set_exits(([
    "south" : VPROOMS "f8_9",
    "west" : VPROOMS "f7_8",
    "wade" : VPROOMS "town9_8"
  ]));
  add_invis_exit("wade");  
}
