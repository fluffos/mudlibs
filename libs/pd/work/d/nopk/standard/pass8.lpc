#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
   set_property("mountain",1);
    set_property("no castle", 1);
    set("short", "Heading down the Daroq Mountain Pass");
    set("long",
	"This pass is the only method of travel through the Daroq "
        "mountains. The mountain walls tower to the north and south "
        "of the pass. From here, it would seem that there are paths "
        "upon the ledges to the north and to the south.");
    set_exits(([ "east" : ROOMS"pass7",
                 "west" : ROOMS"pass9" ]));
}
/*
void reset() {
 ::reset();
   if (!present("gob"))
      new(MOB"gob")->move(this_object());
}
*/
