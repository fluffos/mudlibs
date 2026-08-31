#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 2, "night light" : 2, "indoors" :1 ]) );
   set_short("Guard hut 1");
   set_long("This is a grass hut. "
            "A doorway to the south leads to out and a doorway to the north "
            "seems to lead to another room.");

   set_exits((["out" : ROOMS"hut1",
               "north" : ROOMS"hroom1"]));
 }


void reset() {
   ::reset();
   if (!present("guard")) {
   new(MOB"amazon")->move(this_object());
   new(MOB"guard")->move(this_object());
   new(MOB"guard2")->move(this_object());
   }
}
