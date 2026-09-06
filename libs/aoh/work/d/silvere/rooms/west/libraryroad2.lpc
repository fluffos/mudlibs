// This is a road, that leads to the grand library.
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

int enter_library(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"room")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"library")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You enter the library.\n");
      TP->move(SIL_WEST("libraryenter"),M_GO,"west");
      return 1;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Library road");
   Set(P_INT_LONG,
"This road comes in from the east. You can enter the library of the city\
 to the west. When you walk east, you can find the entrance to the\
 adventurer guild.\n");

   Set(P_INT_WIZMSG,
" WEST:  (or ENTER) the library can be found there.\n\
 EAST:  the guild is on the other end of the road.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("enter",#'enter_library /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -110,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("west",   SIL_WEST("libraryenter"));
   AddExit("east",   SIL_WEST("libraryroad1"));
}
