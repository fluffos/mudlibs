// The entrance to the city park.
// created:       Sonic    [06-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int enter_forest(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"forest")!=-1 ||
      strstr(lower_case(str),"park")!=-1)
   {
      msg_write(CMSG_GENERIC,"You follow the small path into the forest.\n");
      TP->move(SIL_PARK("forest_room1"),M_GO,"east");
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Before a small forest");
   Set(P_INT_WIZMSG,
"The entrance into the small forest is here.\n\
 East: (or ENTER) - a small path into the forest\n\
 West: - to the entrance of the park.\n");

   Set(P_INT_LONG,
      "This is the border of a small forest. A path leads here "
      "from the east and west along a small wall. The path vanishes "
      "between the trees to the east.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("enter",#'enter_forest /*'*/);

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY | REGION_FOREST);
   Set(P_COORDINATES, ({ ({ -170,60,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west",   SIL_PARK("parkenter"));
   AddExit("east",   SIL_PARK("forest_room1"));
}
