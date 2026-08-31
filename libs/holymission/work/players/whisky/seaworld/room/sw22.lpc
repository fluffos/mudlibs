 

#include "../seaworld.h" 
 
void reset(int arg) 
{
  ::reset(arg);

   if (filter_live(this_object()) < 1)
       CM("sword_fish");

    if (arg) return;
    set_light(1);
    short_desc = "In the sea";
    no_castle_flag = 0;
    long_desc =  BS(
        "You have entered the old wreck of a pirate ship.. "
      + "It's normally used as the home of the big swordfish.... "
      + "He is very aggressive and dangerous.... "
      + "He doesn't like humans visiting him, hope that it isn't here.");
    items = ({ "ship","An old pirate ship",
               "water","Dark sea water",
               "bottom","A sandy bottom"}); 
    dest_dir = 
        ({
        PATH+"sw18", "west",
        PATH+"sw23", "south",
        });
}
 
