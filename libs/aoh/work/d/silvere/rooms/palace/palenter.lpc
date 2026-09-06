// The entrance to the palace...
// created:       Sonic    [08-Jul-1997]
// last changed:

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int enter_throneroom(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"throneroom")!=-1 ||
      strstr(lower_case(str),"north")!=-1)
   {
      msg_write(CMSG_GENERIC,"You enter the throneroom of the Lu'meyn.\n");
      TP->move(SIL_PALACE("throneroom"),M_GO);
      return 1;
   }
}

int leave_palace(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"palace")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You leave the palace. "
         "The guards look at you, as you walk by.\n");
      TP->move(SIL_CENTER("palplace5"),M_GO,"south");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A hall in the palace");
   Set(P_INT_LONG,
"This is a large hall in the palace. To the north are doors, leading "
"into the throneroom. To the east and west are archways leading to the "
"east and west wing of the building. To the south is the exit, where "
"the palace can be left.\n");

   Set(P_INT_WIZMSG,
" North: (or Enter) Enter the throneroom of the Lu'meyn.\n"
" South: (or Leave) Back to the city of Silvere.\n"
" West:  To the west wing of the palace.\n"
" East:  To the east wing of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("leave",#'leave_palace /*'*/);
   AddRoomCmd("enter",#'enter_throneroom /*'*/);

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("south", SIL_CENTER("palplace5"));
   AddExit("north", SIL_PALACE("throneroom"));
   AddExit("east",  SIL_PALACE("paleast1"));
   AddExit("west",  SIL_PALACE("palwest1"));
}
