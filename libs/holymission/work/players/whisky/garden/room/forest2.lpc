
 
inherit "/room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
  if (filter_live(TO) < 1)
      CM("boar");

  if (arg) return;
  set_light(0);
  short_desc = "In a dark forest";
  no_castle_flag = 0;
  long_desc =  BS(
    "You are standing in the eastern part of the dark forest. "
  + "You can see many large spruce trees surrounding you. A narrow "
  + "path leads to the southwest and another leads to the "
  + "northwest. You can hear a strange howling coming from the "
  + "west. To the north, east, and northeast the forest leads "
  + "to a beautiful little meadow.");

  dest_dir = ({ ROOM+"/forest1","southwest",
                MEAD+"m2","east",
                MEAD+"m4","north",
                MEAD+"m5","northeast",
		ROOM+"/forest5","northwest",
		ROOM+"/forest4","west" });
  items = ({"trees",
           "They are 60 feet high with large cones hanging from them"});
}
