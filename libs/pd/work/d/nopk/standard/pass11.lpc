#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 1);
   set_property("mountain",1);
    set("short", "Heading down the Daroq Mountain Pass");
    set("long",
        "The pass has begun to smoothen out again, showing "
        "less and less boulder-damage. This part of the pass is "
        "much safer than to the east. A small cave can be seen "
        "only a short walk-distance to the west.");
    set_exits(([ "east" : ROOMS"pass10",
                 "west" : ROOMS"pass12" ]));
}
/*
void reset() {
 ::reset();
   if (!present("child"))
      new(MOB"lost_goblin")->move(this_object());
}

*/
