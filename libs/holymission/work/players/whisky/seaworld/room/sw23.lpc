

#include "../seaworld.h" 

void reset(int arg) 
{
  ::reset(arg);
  if (filter_live(this_object()) < 4)
  {
    CM("baby_shark");
    CM("baby_shark");
    CM("baby_shark");
  }
    if (arg)return;
    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
    "The sea is here nearly black. The water is horrible "
  + "cold here and there are lots of alges swimming "
  + "around. To the west is a sharp little rock "
  + "and to the east a strange cavern.");
    items = ({ "rock","A black rock",
      "cavern","A strange cavern",
      "water","Black sea water",
      "bottom","A sandy bottom" });
    dest_dir = 
    ({
      PATH+"sw25", "east",
      PATH+"sw22", "north",
      PATH+"sw24", "south",
    });
}

