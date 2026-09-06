// This is a small road, that leads to a sell-only shop
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added regions/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>

inherit "/std/shop";

int leave_shop(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"shop")!=-1 ||
      strstr(lower_case(str),"house")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      write("You leave the shop.\n");
      TP->move(SIL_WEST("westshop2"),M_GO,"north");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A little shop");
   Set(P_INT_LONG,
    "This is a little shop. The shopkeeper may know some things "
    "about the city (or about quests, whatever). He sells only some "
    "things and doesn't buy anything.\n");
   Set(P_INT_WIZMSG," NORTH (and LEAVE): back to the road.\n");

   /*
    * Add some details here. *grin*
    */
   Set(P_SELL,0);
   SetDustbin(0,
     ([ P_SHORT:"trashcan",
        P_IDS:({"trash", "trashcan", "dustbin" }),
        P_LONG:"A nice little trashcan.\n"
      ]));

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -150,40,0 }), C_SILVERE }) );

   AddRoomCmd("leave",#'leave_shop /*'*/);

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("north",  SIL_WEST("westshop2"));
}
