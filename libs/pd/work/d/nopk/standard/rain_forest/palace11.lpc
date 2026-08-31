#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("guard room");
   set_long("This is an entrance to a long corridor. Off down "
            "the corridor will be the throne. There are portra"
            "ts of the former rulers along the walls. There i"
            "s a coat of arms hanging on the wall of along the"
            " side");
   set_items((["corridor" : "This is a carpeted hallway with the "
               "throne at the end.",
               "portrats" : "These are beautifly painted portraits "
               "of former rulers.",
               ({"coat", "coat of arms", "arms"}) : "This is a coat "
               "of arms with a lion and a sword, the royal coat of "
               "arms."]));
   set_exits((["east" : ROOMS"palace2",
               "south" : ROOMS"palace12"]));
}

void reset() {
   ::reset();
   if(!present("guard"))
   new(MOB"guard6")->move(this_object());
}
