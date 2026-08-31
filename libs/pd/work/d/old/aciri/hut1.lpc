#include <aciri.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("Inside a grass hut");
   set_day_long(
     "The window openings in the hut let in a great deal of light, as does the "
     "open door. The floor is simply packed down dirt, a refreshing break from "
     "the black sand. The walls and celing of the hut were made out of grass. "
     "This hut is pretty much empty, with the exception of a straw matress.");
   set_night_long(
     "The moonlight is drawn in and magnified by the window opening's position. "
     "The door has been left wide open, a singl epiece of string tying it to the "
     "wall, keeping it ajar. The dirt floor is a welcome change from the hot "
     "black sands of the beach. The small hut is almost empty, save for a straw "
     "matress against the corner."); 
   set_items(([
     "matress" : "A primitive bed; not too comfortable, but better than the "
                 "ground.",
     "ground" : "The ground is composed of packed down dirt.",
     "dirt" : "Packed brown dirt is what the ground consists of.",
     "hut" : "The whole hut is made of grass."
   ]));
   set_properties((["light" : 3, "night light" : 2, "indoors" : 1 ]));
   set_exits(([
      "south" : ROOMS"beach4"
   ]));
}

// string *query_tracks() { return ({ }); }
