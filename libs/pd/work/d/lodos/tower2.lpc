#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a large tower");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1])); 
   set_long("The tower leads up and down. The stairway leads "
            "high into the tower. The blank stone walls lend "
            "a claustrophobic feeling to the tower.");
   set_listen("default", "The sounds of work and muttering can be heard.");
   set_exits(([ "up" : ROOMS"tower3",
                "down" : ROOMS"tower1"]));
   set_property("light", 2);
}

void reset() {
 ::reset();
   if (!present("soldier"))
      new(MOB"soldier")->move(this_object());
}
