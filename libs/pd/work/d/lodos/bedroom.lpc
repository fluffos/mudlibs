#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 1, "night light" : 0,
     "indoors" : 1, "house" : 1 ]));
   set_short("a messy bedroom");
   set_day_long("The bedroom is not very well kept. A little dog sits "
     "on the bed. Sheets have been thrown to the ground, probably by "
     "the dog. The pillows have been ripped up and the bed is in general "
     "disrepair. This room is rather dark because the blinds have been "
     "drawn.");
   set_night_long("The bedroom is in general disrepair, as is the bed. "
     "Sheets are all over the ground, and the pillows have been ripped "
     "up. The room is really dark in the night because the blinds have "
     "been drawn across the window.");
   set_items(([
     "pillows" : "There's gonna be heck when Pipiel finds out.",
     "windows" : "The window is closed and the blinds are drawn.",
     "room" : "The room's pretty dark.",
     "blinds" : "They have been drawn across the window.",
     "sheets" : "They have been thrown disorderly onto the ground.",
     "bedroom" : "It has been messed up by a dog.",     
   ]));
   set_exits(([ "east" : ROOMS"house1" ]));
}

void reset() {
 ::reset();
   if (!present("dog"))
     make(MOB"dog");
}
