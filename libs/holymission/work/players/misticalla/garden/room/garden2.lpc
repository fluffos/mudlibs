 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
  if (filter_live(TO) < 2)
  {
   CM("fox");
   CM("fox");
  }
   if (arg) return;
   set_light(1);
   short_desc = "In a beautiful garden";
   no_castle_flag = 0;
   long_desc = BS(
        "The middle of Chantilly's garden. "
      + "It's a nice place where mother fox is playing with her children. "
      + "But be careful; the mother is looking after her babies. "
      + "To the north, west, and east you can go further into the garden "
      + "and the village shore can be seen to the south.");

  dest_dir = ({ ROOM+"/garden5","north",
		ROOM+"/garden1", "east",
		ROOM+"/garden3", "west",
		"room/vill_shore2","south"
        });
}
