#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Southern wall along the Daroq Mountains Pass");
    set("long",
        "From here, the path along the northern ledge of the mountain "
        "wall can be seen. Far below, the only pass through the Daroq "
        "mountains, the pass has been almost destroyed from falling "
        "boulders. They must have been caused from a rock slide...");
    set_exits(([ "west" : ROOMS"spass9",
                 "east" : ROOMS"spass7" ]));
}

void reset() {
 ::reset();
   if (!present("giant"))
      new(MOB"rock_giant")->move(this_object());
}
