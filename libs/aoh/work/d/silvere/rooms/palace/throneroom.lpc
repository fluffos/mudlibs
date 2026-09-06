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

int leave_throneroom(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"room")!=-1)
   {
      msg_write(CMSG_GENERIC,"You leave the throneroom. ");
      TP->move(SIL_PALACE("palenter"),M_GO);
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"the throneroom");
   Set(P_INT_LONG,
"This is the throneroom of the Lu'meyn, the ruler of Silvere. "
"It's an impressive room with high ceilings and decorated walls "
"and such things.\n");

   Set(P_INT_WIZMSG,
" South: (or Leave) back to the rest of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("leave",#'leave_throneroom /*'*/);

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("south", SIL_PALACE("palenter"));
}
