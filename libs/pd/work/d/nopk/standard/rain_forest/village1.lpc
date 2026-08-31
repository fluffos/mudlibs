#include <rain.h>
#include <std.h>
inherit ROOM;

  void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "town" :1 ]) );
    set_short("Beginning of village");
    set_long("The edge of the village. There is a long "
             "wooden fence blocking entrance for anyone that's not "
             "supposed to be in the village. There are huts on either "
             "side of the path that continues south.");
    set_items((["hut" : "The hut is not very big but is looks pretty "
                        "sturdy.",
                "fence" : "This fence is made up of long wooden poles "
                          "which are very sharp, that are driven into "
                          "the ground facing towards the outside "
                          "of the village"]));
    set_exits((["north": ROOMS"amatrail",
                "south": ROOMS"village2",
                "west" : ROOMS"hut1",
                "east" : ROOMS"hut2"]));

}           


void reset() {
  ::reset();
   if (!present("peasant")) 
      new(MOB"peasant")->move(this_object());
}
