#include <std.h>

inherit VIRTUALROOM;

void create() {
  set_server("/wizards/detach/forbiden/rooms/server");
  ::create();
set_exits((["west":"/wizards/detach/forbiden/rooms/room189",
                "north" : "/d/helgrath/tundra/too/room8",
                "south":"/wizards/detach/forbiden/rooms/room193"]));
add_pre_exit_function("north", "go_south");
}
int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
