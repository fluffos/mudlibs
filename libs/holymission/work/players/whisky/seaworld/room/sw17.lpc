 
#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

    if (filter_live(this_object()) < 1)
       CM("cuttle_fish");

    if (arg) return; 
    set_light(1);
    short_desc = "In the sea";
    long_desc =  BS(
        "Here you are at one of the western corners of the sea. "
      + "The water here is deep and you can hardly see the sun "
      + "shining through the water. It's a bit colder here. "
      + "There are rocks to north and east.");
    items =({ "rock","A big black rock",
              "rocks","Big black rocks",
              "water","Clear sea water",
              "bottom","A sandy sea bottom" });
    dest_dir = 
        ({
        PATH+"sw18", "south",
        PATH+"sw11", "west",
        });
}
