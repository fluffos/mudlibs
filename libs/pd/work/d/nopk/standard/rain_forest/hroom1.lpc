#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("Kitchen");
   set_long("A small kitchen. This room "
            "also apparently doubles for a storage room. There "
            "are many different things piled against the walls "
            "and the cabinets are stuffed.");
   set_exits((["south" : ROOMS"ghut1"]));
   set_items((["cabinets" : "These cabinets are full of food and some "
                            "small weapons are locked in them"]));
  }

void reset() {
   ::reset();
   if (!present(MOB"cook")) 
   new(MOB"cook")->move(this_object());
}
