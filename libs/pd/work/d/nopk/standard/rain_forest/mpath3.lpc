#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Merchant entrance");
    set_long("The merchant dist"
             "rict. Directly to the east is the town square. "
             "To the south are two elven shops. There is "
             "a sign planted in the ground.");
    set_items((["shop" : "The shops are large stone buildings of to "
                         "the south."]));
    set_exits((["north": ROOMS"mpath2",
                "south": ROOMS"mpath4",
                "east": ROOMS"square",
  ]));

}           


void reset() {
  ::reset();
   if (!present("wanderer"))
      new(MOB"traveler")->move(this_object());
}
