 

#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

   if (filter_live(this_object()) < 2)
      CM("whale");

    if (arg) return; 
    set_light(1);
    short_desc = "In the sea";
    long_desc =  BS(
        "Here you are at one of the eastern corners of the sea. "
        + "The water is warm here and pleasant. "
        + "There are big rocks to west,south and east. "
        + "It's a good place for the big whale. "
        + "But don't be afraid he is harmless.");

    items = ({ "rock","A big black rock",
              "rocks","Big black rocks",
              "water","Clear sea water",
              "bottom","A fine sandy sea bottom" });
    dest_dir = 
        ({
        PATH+"sw15", "north",
        });
}
