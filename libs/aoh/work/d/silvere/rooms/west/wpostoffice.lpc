// This is the road to the postoffice
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

int leave_postoffice(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"office")!=-1 ||
      strstr(lower_case(str),"post")!=-1 ||
      strstr(lower_case(str),"building")!=-1 ||
      strstr(lower_case(str),"house")!=-1)
   {
      write("You leave the post office.\n");
      TP->move(SIL_WEST("wpostroad2"),M_GO,"east");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"post office");
   Set(P_INT_LONG,
"This is a rather small room with some private cabins, where you can\
 read your mail. You can leave the office to the east.\n");
   Set(P_INT_WIZMSG,
" EAST:  (or LEAVE) out of here.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("leave",#'leave_postoffice /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -140,10,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("east",  SIL_WEST("wpostroad2"));

   AddItem("/mail/dpost",REFRESH_HOME);
}
