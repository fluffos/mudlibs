inherit "std/room";
#include "path.h"
#include <rooms.h>
#include <moving.h>

climb(string str) {
   if (!str) return 0;
   if (str!="tree") return 0;
   if (!this_player()) return 0;
   this_player()->move(CITY("treetop"),M_GO,"up");
   return 1;
 }

create()
{
    ::create();
    SetIntShort("A clearing");
    SetIntLong("You are on a huge clearing behind the white house.\n" +
	       "There is a high tree standing in the center of the clearing.\n");
    SetIndoors(0);
    AddDetail("tree","Its lowest branches are within your reach. You can climb this tree.\n");
    AddDetail("clearing","A huge tree is standing in its center.\n");
    AddDetail(({"white house","house"}),"You can see it to the south.\n");
    AddExit("climb",#'climb);
    HideExit("climb",1);
    AddExit("north","./clearing1");
    AddExit("south","./nhouse");
}
