#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 1);
    set_property("no castle", 0);
    set("short", "An old house");
    set("long",
          "You have entered an old, mostly run-down shack. A "
          "family of trolls lives here, within the walls of the orc "
          "fortress. The house is mostly empty, though.");
    set_items(
        (["house" : "An old, run-down shack. Stinks, too."]) );
    set_exits( 
                (["west" : ROOMS"south_orcs/open"]) );
}

void reset() {
  ::reset();
    if(!present("child"))
      new(MOB"t_child")->move(this_object());
}
