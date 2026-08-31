
/* kitchen */

inherit "/room/room";
#include "defs.h" 

void reset(int flag)
{
   object poker;

     if (!present("matilda",this_object()))
         CM("matilda");
    if (flag == 0)
    {
      dest_dir = ({
         PATH+"dining_room","north",
      });

       short_desc =  "In the Kitchen";
       long_desc = BS(
         "A hot very hot kitchen, it looks very clean, you can see a store " +
         "room to the south, to the north you can see the dining room.");
       items =
       ({
         "bottom","The bottom is made of fouly wooden lathes",
         "ceiling","The ceiling is dusty and done up",
         "walls","The walls are made of grey bricks"
       });
     }
}

