#include <rooms.h>
#include <regions.h>
#include <properties.h>
#include <coordinates.h>
#include <moving.h>
#include <skills.h>
#include <herbs.h>
#include <nightday.h>
#include <msgclass.h>
#include "forest.h"


inherit FORESTROOM;

varargs void create()
{
  ::create();
   SetIntShort("A forest");
  SetIntLong(
"Standing on a mossy ground you notice a huge forest to the southwest. You \n"
"see a small path leading deeper into the forest. Some bushes are blocking\n"
"the way to the north and west. Far to the west you see the ocean gleaming\n"
"in a dark blue color. Small roots are covering the ground which seem to\n"
"belong to all the vegetation growing here.\n");


SetIntNoise ("There is a silent calmness that surrounds you. "
"Peace enters your soul as you hear animals living happily in the wood. "
"There is a distinctive trickling in the distance.\n");



SetIntSmell (
"The smell of the damp, rich earth relaxes your senses. "
"The ambience of this place is extremely peaceful. Wildflowers tease "
"your nostrils.\n");

AddNoise("trickling","*trickle* *trickle* The sound of water catches "
"you off guard. Is there a stream nearby? It is coming from the "
"southwest.\n");

// --- Added with Softbyte's Detailmaker by Eilan, Aldrana
// Last update: Aldrana at Sun Mar 22 20:49:02 1998
  AddDetail( ({"sw"}),
    "To the southwest, you spy a large, expansive forest. Chills up and down\n"
    "your spine warn you against entering, but your curiosity encourages it.\n");
  AddDetail( ({"southwest"}),
    "To the southwest, you spy a large, expansive forest. Chills up and down\n"
    "your spine warn you against entering, but your curiosity encourages it.\n");
  AddDetail( ({"vegetation"}),
    "The vegetation growing here consists of many different and distinct \n"
    "herbs. The desire to pluck one from the ground is overpowering.\n");
  AddDetail( ({"ocean"}),
    "You admire the ocean from far away. It glimmers as if the sun itself\n"
    "were swimming in it. You can't help but stare.\n");
  AddDetail( ({"roots"}),
"Roots of exotic origin litter the ground here. Is it possible that they\n"
    "have some sort of magical use?\n");
  AddDetail( ({"path","way","little path","small path"}),
    "A little path leads southwest deeper into the forest.\n");
  AddDetail( ({"bush","bushes","some bushes"}),
    "Green bushes are standing around here.\n");
  AddDetail( ({"forest","huge forest"}),
    "To the southwest a huge forest can be seen.\n");
  AddDetail( ({"ground","mossy ground"}),
    "You are standing on a mossy but crumby ground.\n");

  AddExit("southwest","./forestb3");
  AddExit("east","./foresta5");

Set(P_NOWAY_MSG,
"The bushes are far too close together for you to go this way.\n");
}
