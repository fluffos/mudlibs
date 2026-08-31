#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
     set_short("The northern gates of Tirun");
    set_long(
      "The walls of the town run east and west from here. To the south, Veros road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
      "To the north, through the gate, the great northern rainforest begins.");
    set_night_long(
      "The walls of the town run east and west from here. To the south, Veros road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
      "To the north, through the gate, the great northern rainforest begins.");
     set_items(([ "gates" : "The tall, golden gates send a shadow upon the area." ]));
     set_exits(([ "south" : ROOMS+"nveros7",
                   "enter gate" : "/d/nopk/standard/forest1" ]));
add_exit_alias("enter gate", "gate");
}
void reset() {
 ::reset();
    if (!present("guard")){
        new(MOB+"townguard")->move(this_object());
        new(MOB+"townguard")->move(this_object());
   }
   if (!present("gates"))
        new(OBJ+"ngate")->move(this_object());
}
