#include <lodos.h>
#include <std.h>
inherit VAULT;
void look_door();

void create() {
 ::create();
   set_short("At the bottom of a huge tower");
   set_properties((["light" : 2]));
   set_properties((["town" : 1, "indoors" : 1, "building" : 1]));
   set_long("The bottom of the tower is wide and round. The tower leads "
      "up, high up to the clouds. Stairs lead up into the tower. A small "
      "wooden door seperates the tower from a dirt road to the south.");
   set_exits(([ "up" : ROOMS"ntower2",
                "out" : ROOMS"ntown8"]));
   set_items(([ "door" : (: look_door() :) ]));
   set_door("door", ROOMS"ntown8", "out", "");
}

void look_door() {
    if(query_open("door")) write("It is open.");
    else write("It has been closed.");
}

void reset() {
 ::reset();
   if (!present("paladin")) {
     make(MOB"paladin");
     make(MOB"paladin");
     make(MOB"paladin");
   }
}
