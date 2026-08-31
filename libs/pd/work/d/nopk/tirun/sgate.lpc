#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("The southern gates of Sindarii");
    set_long(
      "The walls of the town run east and west from here. To the north, Veros road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
      "To the south, the docks of Tirun birth different sized ships.");
    set_night_long(
      "The walls of the town run east and west from here. To the north, Veros road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
      "To the south, the docks of Tirun birth different sized ships.");
    set_items(([ "gates" : "The tall, golden gates send a shadow upon the area." ]));
    set_exits(([ "north" : ROOMS+"sveros6",
        "enter gate" : ROOMS+"pier" ]));
add_exit_alias("enter gate", "gate");
}
void reset() {
    ::reset();
    if (!present("guard")){
	new(MOB+"townguard")->move(this_object());
	new(MOB+"townguard")->move(this_object());
    }
    if (!present("gates"))
	new(OBJ+"sgate")->move(this_object());
}
