 
#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

   if (filter_live(this_object()) < 2)
   {
     CM("baby_shark");
     CM("baby_shark");
     CM("baby_shark");
   }
    if (arg) return;
    set_light(1);
    short_desc = "In the sea";
    no_castle_flag = 0;
    long_desc =  BS(
        "You are nearly at the northern end of the sea. "
        + "The water here is deep and you can hardly "
        + "see the sun. The water is very cold here. "
        + "If you look north you get a strange feeling, "
        + "maybe father shark is in the near. "
        + "To south there is a big rock.");
    items = ({ "rock","A big black rock",
               "rocks","Big black rocks",
               "water","Dark sea water",
               "bottom","A fine sandy sea bottom" });
    dest_dir = 
        ({
       PATH+"sw22", "east",
       PATH+"sw17", "north",
       PATH+"sw19", "south",
        });
}
 
