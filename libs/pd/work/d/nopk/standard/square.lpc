#include <locations.h>
#include <locations.h>
// Removed June 2001 by Stormy
#include <std.h>
#include <sindarii.h> 
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "light" : 2,  "night light" : 2,  "no steal" : 1,
        "no bump" : 1, "no magic" : 1, "no castle" : 1, "no attack":1 ]));
   set_property("town",1);
   set_listen("default", "A peaceful silence permeates this place.");
   set_short("Tirun Park");
   set_long(
     "You have found yourself in a room that is no longer used. "
     "Please type square to go to the Tirun Square. Thanks. "
   );
    set_exits((["square" : SQUARE_LOC]));
}

