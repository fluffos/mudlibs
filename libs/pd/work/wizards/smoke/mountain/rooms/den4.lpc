#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 1, "indoors" : 1]) );
 set_short("Inside a lions den");
 set_long("The den is such a mess. Some bones are tossed about the floor, "
          "stripped clean. The back of the den can be seen here. ");
    set_items(([
({"bones"}) : "There are bones from all sorts of different victims scattered all"
	" over the floor. A couple of skulls can be seen amidst the other bones.",
({"back"}) : "It almost looks like a room of royalty."
    ]));
    set_exits( ([ 
       "east" :  "/wizards/smoke/mountain/rooms/den3",
       "west" :  "/wizards/smoke/mountain/rooms/den5"
    ]) );
}
void reset() {
    if(!present("lion"))
        new("/wizards/smoke/mountain/monsters/mlion")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion2")->move(this_object());
        new("/wizards/smoke/mountain/monsters/mlion3")->move(this_object());
}
