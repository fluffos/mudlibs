 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
    if (filter_live(TO) < 1)
       CM("wolf");

    if (arg) return;
    set_light(0);
    short_desc = "In a dark forest";
    no_castle_flag = 0;
    long_desc = BS(
        "You are standing in the middle of the dark forest. "
      + "You see many tall spruce trees around you. There is a "
      + "path here that leads to the west, east, and north."
      + "There is a bright light shining from the south. If you "
      + "listen carefully you will hear a grunting sound from the "
      + "east.  A tingling sensation runs up and down your spine.");

  dest_dir = ({ ROOM+"/forest1","south",
		ROOM+"/forest2","east",
		ROOM+"/forest3","west",
		ROOM+"/forest5","north",
        });
   items = ({"trees",
             "Tall trees with large cones hanging down"});
}
