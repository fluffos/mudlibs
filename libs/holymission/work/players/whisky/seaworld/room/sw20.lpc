 

#include "../seaworld.h" 
 
void reset(int arg) 
{
   ::reset(arg);

   if (filter_live(this_object()) < 2)
       CM("baby_shark");

    if (arg) return; 
    set_light(1);
    short_desc = "In the sea";
    long_desc =  BS(
        "Here you are at the eastern areas of the sea. "
      + "The water here is cold and deep and there "
      + "are sometimes alges swimming around.You should "
      + "better leave that place maybe their father is near. "
      + "To the east the water get's nearly black. "
      + "There is a big rock to the south.");
    items = ({ "rock","A big black rock",
               "rocks","Big balck rocks",
               "water","Dark sea water",
               "bottom","A sandy sea bottom" });
    dest_dir = 
        ({
        PATH+"sw24", "east",
        PATH+"sw19", "north",
        PATH+"sw21", "south",
        });
}
