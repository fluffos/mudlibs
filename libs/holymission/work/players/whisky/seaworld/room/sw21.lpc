 

#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

   if (filter_live(this_object()) < 1)
       CM("stone_fish"); 

    if (arg) return; 
    set_light(1);
    short_desc = "In the sea";
    long_desc =  BS(
        "You are at one of the eastern corners of the sea. "
        + "But the water is deep and cold here. "
        + "There are some algae swimming around. "
        + "You should better leave this place south. "
        + "There are big rocks to south and east.");
    items = ({ "rock","A big black rock",
               "rocks","Big black rocks",
               "water","Black sea water",
               "bottom","A sandy sea bottom" });
    dest_dir = 
        ({
        PATH+"sw15", "west",
        PATH+"sw20", "north",
        });
}
