inherit "/std/room";
#include "path.h"

void setup ()   {
set_short("realm of the Gnome:  Tunnels");
set_light(40);
set_long("Macedonia:  Tunnels\n\n"
	 "     You seem to have climbed down into a hole.  This is"
            " a dark cold tunnel.  There is water dripping off"
            " the walls.  The stalactites feel like they are"
         " about to pierce your head.  Straight up there is a"
         " shaft that heads off into more blackness.  The tunnel"
         " continues to the south.\n");
   add_item("stalactites", "These are hanging low to the ground. "
            " They are also sharp.  You better watch out and not"
            " hurt yourself on them.\n");
   add_item("shaft", "This shaft goes straight up.  It would be"
            " impossible to climb up there without some help. "
            " As you look some more you see a rope hanging down"
            " along the edge of the shaft.\n");
add_exit("south",VALLEY +"room04","path");
add_exit("up",UNDER +"under20","path");
}
void init()
{
   ::init();
   add_action("do_climb","climb");
}
int do_climb(string str)
{
   if(str == "up" || str == "rope")
   {
      write("You climb upward through the darkness and stumble "
            "over the edge of the hole.\n");
       this_player()->move("/d/newbie/gnome/tunnels/under20");
      this_player()->look_me();
      return 1;
   }
   else
   {
      write("Climb where?\n");
      return 1;
   }
}
