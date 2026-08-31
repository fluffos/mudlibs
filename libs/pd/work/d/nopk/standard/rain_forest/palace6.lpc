#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
   ::create();
set_properties( ([ "light" : 3, "night light" : 2, "indoors" :1 ]) );
   set_short("At the end of the west passage");
   set_long("The end of a short passage. There "
            "are many pieces of armour and weapons. There is a larg"
            "e spinning wheel over at the corner of the room which "
            "is used to sharpen weapons.");
   set_items((["armour" : "Many random pieces of armour lie "
               "around the room",
               "weapons" : "There are some different weapons laying around",
               "stone" : "This stone used to be able to sharpen wea"
               "pons but it broke"]));
   set_exits((["east" : ROOMS"palace5"]));
}

void reset() {
   ::reset();
   if(!present("chief"))
   new(MOB"chief")->move(this_object());
}
