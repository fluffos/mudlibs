 

#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

   if (filter_live(this_object()) < 1)
      CM("saw_fish");

    if (arg) return;
    set_light(1);
    short_desc = "In the sea";
    long_desc =  BS(
        "Here you have entered a deep and cold area in the sea. "
        + "There are alges swimming around an there is some "
        + "wood lying on the bottom. There is a big black rock "
        + "to the south and east.");
    items = ({ "wood","Heavy pieces of brown wood",
               "alges","Some green alges",
               "water","Dark sea water",
               "bottom","A sandy sea bottom" });
    dest_dir = 
        ({
        PATH+"sw23", "north",
        PATH+"sw20", "west",
        });
}
