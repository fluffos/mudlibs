#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
     set_short("The eastern gates of Tirun");
    set_long(
      "The walls of the town run north and south from here. To the west, Honin road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
     "To the east, through the gate, the great eastern expanse begins.");
    set_night_long(
      "The walls of the town run north and south from here. To the west, Honin road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
     "To the east, through the gate, the great eastern expanse begins.");
     set_items(([ "gates" : "The tall, golden gates send a shadow upon the area." ]));
     set_exits(([ "west" : ROOMS+"ehonin6",
                     "enter gate" : "/d/nopk/standard/outland1" ]));
add_exit_alias("enter gate", "gate");
}
void reset() {
 ::reset();
    if (!present("guard")){
        new(MOB+"townguard")->move(this_object());
        new(MOB+"townguard")->move(this_object());
   }
   if (!present("gates"))
        new(OBJ+"egate")->move(this_object());
}
