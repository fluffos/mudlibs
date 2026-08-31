#include <std.h>

inherit VAULT;

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 4\nThe door to the west is being blocked by a "
             +"door and a gate. There are two holes in the ceiling, "
             +"a ladder leads up to one of them, but it is being "
             +"covered by a manhole. The other one is uncovered.");

  set_exits(([ "west" : "/wizards/pyro/doors/sample3",
               "up"   : "/wizards/pyro/doors/sample5" ]));
  cover_exit_with_door("west", "pyrodoor3");
  cover_exit_with_door("west", "pyrodoor4");
  cover_exit_with_door("up", "pyrodoor5");
  set_door_name("pyrodoor5", "manhole");
  //only one of the rooms has to have the name sets in it, but I put it in both just to be sure.
  //even though nobody should ever encounter this room first, you never know.
  set_door_name("pyrodoor4", "gate");
}
