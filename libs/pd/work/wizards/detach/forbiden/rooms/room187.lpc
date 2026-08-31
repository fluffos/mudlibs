#include <std.h>
inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
 
 
set_exits((["east":"/wizards/detach/forbiden/rooms/room188",
                "north" : "/d/helgrath/tundra/too/room6",]));
add_pre_exit_function("north", "go_south");
}
int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
