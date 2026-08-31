#include <rain.h>
#include <std.h>
inherit ROOM;

void create(){
   ::create();
set_properties( ([ "light" : 3, "night light" : 1, "forest" :1 ]) );
    set_property("forest", 1);
   set_name("Termite room");
   set_short("Termite room");
   set_long("This is the end of a sandy path through the forest."
            " Here, deep in the forest, there is the noise of"
            " skittering from under the forest undergrowth.");
   set_items((["ground" : "This ground is loose ground which will move"
                          " and shift around.",
               "trees" : "There are a few green trees scattered around you"]));
   set_exits((["southeast" : ROOMS"dirtwest"]));

 }

void reset() {
  ::reset();

       if (!present("termite")) {

       new(MOB"termite")->move(this_object());
       new(MOB"termite")->move(this_object());
       new(MOB"termite")->move(this_object());
       }
  }
