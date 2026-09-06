// A small road, that leads to a smith.
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

int enter_smith(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"shop")!=-1 ||
      strstr(lower_case(str),"smith")!=-1)
   {
      write("You enter the shop of the weaponsmith.\n");
      TP->move(SIL_WEST("weaponsmith"),M_GO,"north");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"small road");
   Set(P_INT_LONG,
"This is a small road, that ends here before a shop. Then entrance is to\
 the south. The road leads back to the west.\n");
   Set(P_INT_WIZMSG,
" WEST:  back to the crossing.\n\
 SOUTH: (or ENTER) the shop of the weaponsmith.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("enter",#'enter_smith /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -130,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("west",   SIL_WEST("wsmithroad1"));
   AddExit("south",  SIL_WEST("weaponsmith"));
}
