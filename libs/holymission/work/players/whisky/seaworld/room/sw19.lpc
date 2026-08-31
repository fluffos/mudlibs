 

#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);
  
  if (filter_live(this_object()) < 1)
      CM("octopus");

    if (arg) return; 
    set_light(1);
    short_desc = "In the sea";
    long_desc =  BS(
        "You have now entered a cold and deep area of the sea. "
      + "There is an old ship lying at the bottom, but it's too deep. "
      + "It's the favorite area of the big octopus. The octopus "
      + "is big and dangerous...you'd better leave that place.. "
      + "You can see a big rock to the west and to the east.");
    items = ({ "rock","A big black rock",
               "rocks","Big black rocks",
               "ship","An old pirate ship",
               "water","Clear sea water",
               "bottom","A sandy sea bottom" });
    dest_dir = 
        ({
        PATH+"sw18", "north",
        PATH+"sw20", "south",
        });
}
int id(string arg) { return arg=="sea"; }
int query_weight() { return 0; }
int get() { return 1; }
