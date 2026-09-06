// The entrance to the forest
// created:       Sonic    [06-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int leave_forest(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"forest")!=-1 ||
      strstr(lower_case(str),"park")!=-1)
   {
      msg_write(CMSG_GENERIC,"You follow the small path to the west.\n");
      TP->move(SIL_PARK("forest_enter"),M_GO,"east");
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"At the border of a small forest");
   Set(P_INT_WIZMSG,
"This is the border of a small forest.\n\
 West: (or LEAVE) - a small path to the entrance of the park\n\
 South: - Deeper into the forest.\n");

   Set(P_INT_LONG,
      "This is the border of a small forest. A path comes into "
      "the forest from the west and continues to the south deeper "
      "into the forest.\n");

   /*
    * Add some details here. *grin*
    *
    * maybe a little climb command, that gives a message, that that
    * is not possible, because you are too heavy for the trees or
    * something else. Or the branches are too high...
    */

   AddRoomCmd("leave",#'leave_forest /*'*/);

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_FOREST | REGION_CITY);
   Set(P_COORDINATES, ({ ({-160,60,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west",   SIL_PARK("forest_enter"));
   AddExit("south",  SIL_PARK("forest_room2"));
}
