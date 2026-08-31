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
        "Gaping holes litter the pass here. The holes look as though "
        "they were caused from rock slides and avalanches. The ledge "
        "above looks very unstable. A cool wind adds a nice touch to "
        "the calm heat of the mountains.");
    set_exits(([ "east" : ROOMS"pass8",
                 "west" : ROOMS"pass10" ]));
}
/*
void reset() {
 ::reset();
   if (!present("gob"))
      new(MOB"gob")->move(this_object());
}
*/
