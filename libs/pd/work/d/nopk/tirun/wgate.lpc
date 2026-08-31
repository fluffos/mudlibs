#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
     set_short("The western gates of Tirun");
    set_long(
      "The walls of the town run north and south from here. To the east, Honin road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
      "To the west, through the gate, the great western mountain range begins.  A "
      "small crack can be seen near the gates.");
    set_night_long(
      "The walls of the town run north and south from here. To the east, Honin road leads the way "
      "to the center of town. A set of gates hung on the wall can be closed to protect the city. "
      "To the west, through the gate, the great western mountain range begins.");
     set_items(([ "gates" : "The tall, golden gates send a shadow upon the area." ]));
     set_exits(([ "east" : ROOMS+"whonin7",
"crack" : "/d/guilds/unholy/entrance",
                     "enter gate" : "/d/nopk/standard/highway1" ]));
set_invis_exits(({"crack"}));
add_exit_alias("enter gate", "gate");
}
void reset() {
 ::reset();
    if (!present("guard")){
        new(MOB+"townguard")->move(this_object());
        new(MOB+"townguard")->move(this_object());
   }
   if (!present("gates"))
        new(OBJ+"wgate")->move(this_object());
}
