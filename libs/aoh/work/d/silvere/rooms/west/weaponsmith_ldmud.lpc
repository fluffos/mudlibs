// This is the shop of the weaponsmith. He repairs and sells weapon, but doesn't buy
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <skills.h>
#include <rooms.h>
inherit "/room/smithy";

int leave_smith(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"shop")!=-1 ||
      strstr(lower_case(str),"smith")!=-1)
   {
      write("You leave the shop of the weaponsmith.\n");
      TP->move(SIL_WEST("wsmithroad2"),M_GO,"north");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"weaponsmith");
   Set(P_INT_LONG,
"This is the shop of the weaponsmith. He creates and repairs weapons\
 but doesn't buy anything. The exit is to the north\n");

   Set(P_INT_WIZMSG," NORTH: (or LEAVE): leave the shop.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("leave",#'leave_smith /*'*/);

   Set(P_SELL,0);
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -130,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("north",  SIL_WEST("wsmithroad2"));
}
