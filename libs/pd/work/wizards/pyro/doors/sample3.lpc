#include <std.h>

inherit VAULT;

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 3\nThere is a door blocking the west exit and"
           +"a door and a gate blocking the east exit. You're going to have to open both the door and the gate to the east to continue, or you can just <open east> to attempt to open them both at the same time.");

  set_exits(([ "west" : "/wizards/pyro/doors/sample2",
               "east"  : "/wizards/pyro/doors/sample4",
           ]));
  cover_exit_with_door("west", "pyrodoor2");
  cover_exit_with_door("east", "pyrodoor3");
  cover_exit_with_door("east", "pyrodoor4");
  set_door_name("pyrodoor4", "gate");
}
