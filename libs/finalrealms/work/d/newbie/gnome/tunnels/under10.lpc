inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1);
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"	
	"     This area of the tunnels looks to have been mined at "
   "at one point in time.  There is still a large pile of rubble here "
   "and the walls seem to be slightly chiseled from enterprising "
   "gnomes who were searching for ore with which to make their inventions. "
   "You start to go northeast but a small shaft of light catches "
    "your eye, and you notice that it is coming from a crack in the ceiling.\n\n");
add_item(({"crack","shaft","ceiling","hole","light"}),"As you look at the shaft of "
   "light you notice that it is comming from a crack high "
   "above you.  You wonder at how you are going to get up there.\n\n");
add_item(({"walls","wall","floor","ceiling"}),"You look at the "
   "walls and the ceiling and notice how rough this room looks.  "
   "The walls are all sharp and jaged from rough mining and it "
   "doesn't even look as if the newbie/gnomes finished since there is a "
   "bunch of debris left aobut the room.\n\n");
add_item(({"rubble","pile"}),"You look closely at the rubble and notice that "
   "while it seems to be piled up rather haphazardly, you can see "
   "a kind of path that looks climbable and leads to the top of the "
   "pile of rubble.\n\n");
add_exit("northeast",UNDER +"under04","path");
}
void init()
{
   add_action("do_climb","climb");
   ::init();
}
int do_climb(string str)
{
   if(str == "rubble")
   {
      if(this_player()->query_level() >= 5)
      {
      write("You stumble over this rubble to clearly see ...\n\n");
	this_player()->move("/d/newbie/gnome/rooms/room02");
      this_player()->look_me();
      }
      else
      {
          write("You try amazingly hard to climb the rubble, but slide back down, you are too young and inexperienced a Gnome to do that.... now anyway, try again later maybe ?.\n");
      }
      return 1;
   }
}
