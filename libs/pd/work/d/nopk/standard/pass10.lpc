#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("night light", -2);
   set_property("mountain",1);
    set_property("light", 0);
    set("short", "Heading down the Daroq Mountain Pass");
    set("long",
        "The path here is a little banged up from rock slides, but "
        "not nearly as much as to the east. The mountain walls cast a "
        "shade down upon the path, so dark, it seems like night here "
        "the entire day long.");
    set_exits(([ "east" : ROOMS"pass9",
                 "west" : ROOMS"pass11" ]));
}

void reset() {
 ::reset();
   if (!present("child"))
      new(MOB"lost_goblin")->move(this_object());
}

