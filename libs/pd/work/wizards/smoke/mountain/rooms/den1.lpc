#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a lions den");
 set_long("This looks as though it's a lions den. Some bones are tossed about "
          "the floor, stripped clean. The back of the den cannot be seen here.
");
    set_items(([
({"bones"}) : "There are bones from all sorts of different victims scattered
all"
         " over the floor. A couple of skulls can be seen amidst the other
bones."
    ]));
    set_exits( ([ 
       "out" :  "/wizards/smoke/mountain/rooms/5",
       "north" :  "/wizards/smoke/mountain/rooms/den2"
    ]) );
}
void reset() {
    if(!present("lion"))
        new("/wizards/smoke/mountain/monsters/mlion3")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion2")->move(this_object());
}
