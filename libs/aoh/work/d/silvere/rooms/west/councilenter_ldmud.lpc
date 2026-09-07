// A broad road, that leads to the Council Hall.
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

int leave_council(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"hall")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You leave the Council Hall.\n");
      TP->move(SIL_WEST("councilroad4"),M_GO,"west");
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Council Hall Entrance");
   Set(P_INT_LONG,
"This is the entrance to the council hall. As there is nothing here\
 nothing can be seen. The clocktower is supposed to be here and maybe\
 some people of the city council or whatever.\n");

   Set(P_INT_WIZMSG,
" WEST: (or LEAVE) Out of the building.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("leave",#'leave_council /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_COORDINATES, ({ ({ -90,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("west",  SIL_WEST("councilroad4"));
}
