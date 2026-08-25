inherit "/std/room";
#include "path.h"

void setup ()   {
add_property("no_undead",1); 
set_short("Realm of the Gnome:  Macedonian Tunnel");
set_light(40);
set_long("\nRealm of the Gnome:  Macedonian Tunnel\n\n"
	 "     You have followed the stream to its end. "
      "You watch as it quietly dissappears down into a dark bottomless "
      "hole.  You look down the hole and can see nothing but blackness. "
     "You look up and notice that it seems as if this cavern has been "
    "left undisturbed, for there are several columns that have "
     "been formed by stalagtites and stalagmites joining together.\n\n");
add_item(({"hole","pit","bottomless"}),"As you look at the "
   "hole, you are wanting to climb down in it.  You notice a rope "
   "tied to the column which might be of assistance.\n\n");
add_item(({"column","stalagtite","stalagmite","stalagtites","stalagmites"}),
      "The columns are formed by the connection of a stalagtite "
      "and a stalgmite.  This would give a good support for "
      "rapelling.  As you look closely at the column closest to "
      "hole, you notice a rope which you could climb down on ... "
      "that is if you know how to climb a rope good enough.\n\n");
add_exit("north",UNDER +"under18","path");
add_exit("northeast",UNDER +"under19","path");
}
void init()
{
   ::init();
   add_action("do_climb","climb");
}
int do_climb(string str)
{
   if(str == "down" || str == "rope") 
      {
      if((int)this_player()->query_property("skill_rope_climbing"))
         {
            write("You slowly climb down the rope, lowering yourself "
                  "into the blackness of the hole.  You finally reach the "
                  "bottom and see:  \n");
	this_player()->move("/d/newbie/gnome/rooms/room03");
            this_player()->look_me();
            return 1;
         }
         else
         {
            write("You sure wish you know how.\n");
            return 1;
         }
      }
      else
      {
         write("Climb what?\n");
         return 1;
      }
}
