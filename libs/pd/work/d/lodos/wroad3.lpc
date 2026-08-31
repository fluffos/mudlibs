#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Heading west, towards the town gates");
   set_long("The town gates can be seen just to the west of here, "
      "although the square to the east is just out of sight. The silver "
      "gates glisten in the light. A cool breeze shakes the trees.");
   set_items(([ "temple" : "It is to the east of here." ]));
   set_exits(([ "east" : ROOMS"wroad2",
                "west" : ROOMS"wroad4"]));
   set_properties(([ "light" : 2, "town" : 1 ]));
}

void reset() {
 ::reset();
   if (!present("citizen")) {
      new(MOB"citizen")->move(this_object());
      new(MOB"citizen")->move(this_object());
   }
}
