#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
 ::create();
   set_property("light", 2);
   set_property("night light", 1);
   set_property("no castle", 1);
   set_short("Heading south through the orc fortress");
   set_long(
        "The dirt path leads southwards through the orc fortress. "
        "To the north there is a small clearing, and to the south is "
        "a larger hut, probably belonging to some important official.");
   set_exits((["north" : ROOMS"south_orcs/path3"]));
}

void reset() {
 ::reset();
   if (!present("worker"))
     new(MOB"worker")->move(this_object());
}
