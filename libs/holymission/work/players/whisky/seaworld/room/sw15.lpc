 

#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 2)
  {
    CM("stone_fish");
    CM("stone_fish");
  }
  if (arg) return;

    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
        "You have now entered a deeper area of the sea. "
        + "The water here is very warm and pleasant. "
        + "This area is nearly optimal for the dangerous. "
        + "stone fish. It is harmless, but has a poisonous "
        + "fang. To the north the sea gets darker.");
    items = ({"bottom","A sandy bottom",
              "water","Clear sea water" });
    dest_dir = 
        ({
        PATH+"sw21", "east",
        PATH+"sw9", "west",
        PATH+"sw14", "north",
        PATH+"sw16", "south",
        });
}

