 
inherit "room/room";
#include "../garden.h" 
 
void reset(int arg) 
{
   if (filter_live(TO) < 3)
   {
    CM("bunny");
    CM("bunny");
   }
    if(arg) return; 
    set_light(1);
    short_desc = "In a beautiful garden";
    no_castle_flag = 0;
    long_desc = BS(
      "This is the bunny corner of Chantilly's beautiful garden. "
    + "The sun is shining on your face and you would like to stay here "
    + "forever. There is a brown garden fence to the north and west."
    + " "
   + "A thick green vine hangs majestically down from the clouds.");

    items = ({ "fence","You see a big brown garden fence" });
    dest_dir = ({
		  ROOM+"/garden2","south",
                  "/players/misticalla/area/rooms/vine01","up",
		  ROOM+"/garden4","east" });
}

init() 
{
  add_action("climb","climb");
  ::init();
}

int climb(string str) 
{
  if (str=="fence") {
     write("You try to climb over the fence ...\n"
	+ "At this side, the fence is to high to climb over.\n");
     return 1;
  }
  return 0;
}
