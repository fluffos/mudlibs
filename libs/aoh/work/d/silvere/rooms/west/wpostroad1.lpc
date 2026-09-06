// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <macros.h>
inherit SILBASEROOM;

int enter_building(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"office")!=-1 ||
      strstr(lower_case(str),"building")!=-1 ||
      strstr(lower_case(str),"post")!=-1)
   {
      write("You enter the post office.\n");
      TP->move(SIL_WEST("wpostoffice"),M_GO,"east");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westroad");
   Set(P_INT_LONG,
      "This is a road, that leads from north to south. The postoffice "
      "is now located to the NORTH of here.\n");

   Set(P_INT_WIZMSG,
      " NORTH: to the postoffice.\n"
      " SOUTH: to the mainroad.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("enter",SF(enter_building));

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -140,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("north",  SIL_WEST("wpostroad2"));
   AddExit("south",  SIL_WEST("westroad5"));
   AddExit("east",   SIL_WEST("wpostoffice"));
}
