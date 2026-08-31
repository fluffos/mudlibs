
 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
   if (filter_live(TO) < 1)
      CM("girl");

   if (arg) return;
     set_light(1);
     short_desc = "On a small path";
     no_castle_flag = 0;
     long_desc = BS(
       "You are coming closer and closer to the dark forest. "
     + "You can hear strange voices coming from there. "
     + "To the west and east you can see some thick bushes "
     + "and to the very south you can see the garden fence of "
     + "Chantilly's beautiful garden.");

     dest_dir = ({ ROOM+"/forest1","north",
                   "/players/emerald/seaworld/room/sea_way", "east",
		   ROOM+"/path1","south" });
     items = ({ "fence", "A big brown garden fence",
    	        "bushes", "Big bushes almost 3 feet high"});
}
