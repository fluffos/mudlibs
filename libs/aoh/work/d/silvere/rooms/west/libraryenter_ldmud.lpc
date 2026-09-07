// This is the library of the City
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

int leave_library(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"room")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"library")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You leave the library.\n");
      TP->move(SIL_WEST("libraryroad2"),M_GO,"east");
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"The Adventurers Guild");
   Set(P_INT_LONG,
"This is the entrance to the library. To the east you can leave the\
 building to the library road.\n");

   Set(P_INT_WIZMSG,
" EAST:  (OR LEAVE) the road to the library\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("leave",#'leave_library /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -120,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("east",   SIL_WEST("libraryroad2"));
}
