#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Guard room");
    set_long("The boundaries of an elven fortress. "
             "A guard barracks is here to make sure no trouble is brought into town.");
    set_items((["barracks" : "There are guard barracks to the north"
                             "east and northwest."]));
    set_exits((["north": ROOMS"village1",
                "south": ROOMS"village3"]));

}           


void reset() {
  ::reset();
   if (!present("elven guard")) {
      new(MOB"bguard")->move(this_object());
      new(MOB"bguard")->move(this_object());
   }
}
