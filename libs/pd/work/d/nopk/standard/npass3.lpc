#include <std.h>
#include <sindarii.h>
inherit ROOM;
void create() {
 ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Northern path of the Daroq Mountain pass");
    set("long",
        "Although the ledge here is rather stable and safe, as "
        "the path leads west, along the side of the pass, the ledge "
        "becomes much thiner. A cool wind chills your bones.");
    set_exits(([ "west" : ROOMS"npass4",
                 "down" : ROOMS"npass2" ]));
}
void reset() {
 ::reset();
   if (!present("daroq"))
      new(MOB"takdar")->move(this_object());
}
