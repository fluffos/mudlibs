#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 2, "night light" : 2, "indoors" :1 ]) );
   set_short("Guard hut 1");
   set_long("This is a grass hut. A doorway to the south leads "
            "out and another doorway to the north seems to lead "
            "to another room.");

   set_exits((["out" : ROOMS"hut2",
               "north" : ROOMS"hroom3"]));
 }


void reset() {
   ::reset();
   if (!present("guard")) {
   new(MOB"amazon")->move(this_object());
   new(MOB"guard")->move(this_object());
   }
}
