#include <rain.h>
#include <std.h>
inherit ROOM;

void create(){
   ::create();
    set_property("forest", 1);
    set_properties( ([ "light" : 3, "night light" : 1]) );
   set_name("antlion room");
   set_short("antlion room");
   set_long("This is the end of a dirt path through the forest."
            " There are a few trees and shrubs around. ");
   set_items((["ground" : "This ground is loose ground which will move"
                          " and shift around.",
           "trees" : "There are a few green trees scattered around you"]));
   set_exits((["northeast" : ROOMS"dirtwest"]));

 }

void reset() {
   ::reset();

        if (!present("antlion")) {

        new(MOB"antlion")->move(this_object());
        new(MOB"antlion")->move(this_object());
        new(MOB"antlion")->move(this_object());
        }
  }
