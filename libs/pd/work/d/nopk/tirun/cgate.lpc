#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
     set_short("The cemetary gates of Tirun");
   set_long(
     "The walls of the town run north and south from here. To the west, Wayward Avenue leads the way "
     "into town. A set of gates hung on the wall can be closed to protect the city. "
     "To the east, through the gate, the cemetary lies.");
   set_night_long(
      "The walls of the town run north and south from here. To the west, Honin road leads the way "
      "into town. A set of gates hung on the wall can be closed to protect the city. "
      "To the east, through the gate, the cemetary lies.");
    set_exits( ([
                "west" : ROOMS"ewayward7",
"east" : "/d/nopk/standard/cemetary/gravyar2",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
void reset() {
 ::reset();
    if (!present("guard")){
        new(MOB+"townguard")->move(this_object());
   }
   if (!present("gates"))
        new(OBJ+"cgate")->move(this_object());
}
