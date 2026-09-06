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

int enter_guild(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"guild")!=-1 ||
      strstr(lower_case(str),"room")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You enter the guild.\n");
      TP->move(SIL_WEST("adventurerguild"),M_GO,"east");
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
"This road leads from the mainroad at the north to the library at\
 the west. You can enter the adventurers guild to the east, as soon\
 as it is finished.\n");

   Set(P_INT_WIZMSG,
" WEST:  the library can be found there.\n\
 EAST:  (or ENTER) this is, where the guild can be entered.\n\
 NORTH: back to the mainroad.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("enter",#'enter_guild /*'*/);
   Set(P_INT_MAP,"silvere1");
   Set(P_COORDINATES, ({ ({ -100,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("north",  SIL_WEST("westroad9"));
   AddExit("west",   SIL_WEST("libraryroad2"));
   AddExit("east",   SIL_WEST("adventurerguild"));
}
