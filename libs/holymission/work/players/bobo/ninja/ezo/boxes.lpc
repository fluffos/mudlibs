
// coded by whisky: please never remove boxes.o !
inherit "/players/whisky/obj/std_boxes";
#include "/players/whisky/genesis/sys/break_string.h"

#define BS(x) break_string(x+"\n",60) 

void reset(int flag)
{
     ::reset(flag);
     if (flag==0)
     {
       set_light(1);
       short_desc = "The box chamber";
       long_desc = BS(
       "You have entered a small dusty room. There is a counter "+
       "and a big wooden shelf fixed to the wall. Inside the "+
       "shelf you can see a lot of boxes and 'Yamalicko' the blue "+
       "robed ninja counting and cleaning the items stored in the "+
       "boxes. There is a iron sign hanging on the wall.");
    
       items =
       ({
          "bottom","You see an oak wooden bottom",
          "wall","The walls are made of red bricks",
          "walls","The walls are made of red bricks",
          "shelf","The shelf is full with boxes",
          "boxes","The boxes are to store items",
          "sleepy","He is counting and cleaning the items in the boxes",
          "iron sign","There is something written on it",
          "sign","There is something written on it"
       });
       dest_dir =
       ({
         "/players/tatsuo/ezo/store","east" });
      clerk = "Yamalicko";
        save_file = "/players/tatsuo/ezo/boxes";
        cost = 1000; /* per week */
        ::check_boxes();
      }
 }
      
init()
{
write("BOX ROOMS REMOVED SIX MONTHS AGO, ILLEGAL TELEPORT, LOGGED\n");
write("PLEASE MEM ANOTHER SITE, BOX ROOM BUGS THE MUD, REMOVED\n");
this_player()->move_player("to the church#room/church");
return 1;
  ::init();
}
