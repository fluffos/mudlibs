#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties((["indoors" : 1, "light" : 2,
                    "night light" : 1]));
   set_short("East side of a temple");
   set_day_long("This room is the east-most side of the main temple. Two doorways "
     "are connected to here, one leading north and another south. Along the "
     "eastern wall are stained glass windows and along the western side are "
     "paintings and tapestries. All paintings, tapestries and windows depict a "
     "variety of different religious figures and scenes.");
   set_night_long("This room is the east-most side of the main portion of this "
     "magnificent temple. Darkness casts quite an eerie shadow upon this temple "
     "room. All of the normally white and grey walls and floor have turned a "
     "dark grey and black from the night shadows. Tapestries line the western wall "
     "and stained glass windows the eastern.");
   set_items(([
     "paintings" : "The paintings are almost all portraits of old priests and "
                   "monks.",
     "tapestries": "They are mostly of landscapes; both real and heavenly.",
     "windows"   : "The stained glass windows are a wonderous sight to behold "
                   "when the sunlight shines through them just right.",
     "floor"     : "Floor and walls are mostly white. The floor is tiled.",
     "walls"     : "Floor and walls are mostly white, though the walls have a "
                   "bit of grey in them; the walls are onyx."
   ]));
   set_exits(([ "north" : ROOMS"l1m3",
                "south" : ROOMS"l1m9"
   ]));
}
/*
void reset() {
 ::reset();
   if (!present("man"))
     make(MOB"oldrobed");
}
*/
