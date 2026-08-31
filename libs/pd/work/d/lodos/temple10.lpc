#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a temple to Omicron");
   set_properties((["town" : 1, "indoors" : 1, "building" : 1,
     "light" : 2])); 
   set_long("The royal blue walls lead north and east. "
            "A calm feeling comes over you here. The air "
            "of the temple is so relaxing, you almost have "
            "to fight off sleep.");
   set_items(([ "walls" : "They are a royal in color.",
                "tiles" : "The tiles on the ground are a light grey."
            ]));
   set_exits(([ "east" : ROOMS"temple8",
                "north" : ROOMS"temple10" ]));
}

void reset() {
 ::reset();
   if (!present("monk"))
      new(MOB"monk1")->move(this_object());
}

