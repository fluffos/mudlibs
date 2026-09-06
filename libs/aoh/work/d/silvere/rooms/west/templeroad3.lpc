// This is a small road, that leads toward the temple to the northeast
// created:       Sonic    [29-May-1997]
// last changed:  Chara    [6-June-1997]
//                Chara    [7-June-1997]
//                Sonic    [01-Jul-1997]  Added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

int enter_temple(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"temple")!=-1)
   {
      write("You enter the temple of Xalandre.\n");
      TP->move(SIL_WEST("xal_temple"),M_GO,"east");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Templeroad");
   Set(P_INT_LONG,
"The small road ends here at the temple of Xalandre. The temple exudes a "
"feeling of peace and serenity. Its sparkling white walls make a nice "
"contrast with the vivid green grass that grows around it and the palm "
"trees that cast a cooling shade on its walls. The entrance to the temple "
"is to the east.\n");

   AddDetail("temple",
    "The temple of Xalandre is white and sparkling, and you feel refreshed "
    "just looking at it.\n");

   AddDetail("grass",
    "The grass is green and lush, and looks delightful to walk on.\n");

   AddDetail( ({"palm", "palms", "tree", "trees", "palm trees"}),
    "The palm trees sway gently in the breeze.\n");

   AddDetail( ({"sea", "ocean"}),
    "You cannot see the ocean from here, but from its sound and smell, "
    "you know it must be close.\n");

   AddDetail( ({"road", "path"}),
    "The dirt path is almost at its end here.\n");

   AddDetail( ({"wall", "city wall"}),
    "The defensive wall is the only thing between the temple and the "
    "beach.\n");

   Set(P_INT_NOISE,
    "You can hear the wooshing of the sea from the other side of the city "
    "wall, as well as the harsh cawing of seagulls.\n");

   Set(P_INT_SMELL,
    "The tangy scent of fish and brine fill your nostrils.\n");

   Set(P_INT_WIZMSG,
" WEST: back to the main road.\n\
 EAST: enter the temple.\n");

   AddRoomCmd("enter",#'enter_temple /*'*/);
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -160,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
    "The path doesn't go that way.\n");
   AddExit("west",   SIL_WEST("templeroad2"));
   AddExit("east",   SIL_WEST("xal_temple"));
}
