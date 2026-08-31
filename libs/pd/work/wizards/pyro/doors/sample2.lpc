#include <std.h>

inherit VAULT;

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 2\nThere is a door blocking the south exit and"
           +" a door blocking the east exit. You may have to either <open door> or <open door 2> to open the east door. You can also <open east> to open the eastern door.");

  set_exits(([ "south" : "/wizards/pyro/doors/sample1",
               "east"  : "/wizards/pyro/doors/sample3" ]));
  cover_exit_with_door("south", "pyrodoor1");
  cover_exit_with_door("east", "pyrodoor2");
}
