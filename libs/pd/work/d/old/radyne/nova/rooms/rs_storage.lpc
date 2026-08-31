#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "indoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Radyne General Inventory and Storage");
   set_long(
     "Radyne General's inventory. Bits and pieces of odds and ends "
     "are placed neatly around the room, on shelves and in crates. "
   );
   set_exits( ([
      "east" : ROOMS "gshop",
   ]) );
    new("/d/tirun/obj/misc/vial")->move(this_object());
    new("/d/tirun/obj/misc/vial")->move(this_object());
    new("/d/tirun/obj/misc/torch")->move(this_object());
    new("/d/tirun/obj/misc/torch")->move(this_object());
    new("/d/tirun/obj/misc/torch")->move(this_object());
    new("/d/tirun/obj/misc/torch")->move(this_object());
    new("/d/tirun/obj/misc/bag")->move(this_object());
    new("/d/tirun/obj/misc/bag")->move(this_object());
    new("/d/tirun/obj/misc/bag")->move(this_object());
}


