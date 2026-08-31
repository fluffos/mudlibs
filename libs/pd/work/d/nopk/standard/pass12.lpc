#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
    set_property("mountain",1);
    set("short", "Heading down the Daroq Mountain Pass");
    set("long",
      "The southern wall of the pass seem to be coming a little "
      "closer to the pass itself. The ledge looks safe enough to "
      "climb up on to. A small cave, leading into the ground can "
      "be seen just to the west.");
    set_exits(([ "east" : ROOMS"pass11",
	"west" : ROOMS"pass13" ]));
}
/*
void reset() {
 ::reset();
   if (!present("child"))
      new(MOB"lost_goblin")->move(this_object());
}

*/
