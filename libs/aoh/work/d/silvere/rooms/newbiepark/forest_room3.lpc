// This is the forest, which contains the newbie monsters
// created:       Sonic    [06-Jun-1997]
// last changed:  Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int climb_wall(string str)
{
   notify_fail("Climb what?\n",NOTIFY_ILL_ARG);
   if(!TP)  return 0;
   if(!str) return 0;
   if(strstr(lower_case(str),"wall")!=-1 ||
      strstr(lower_case(str),"up")!=-1)
   {
      msg_say(CMSG_GENERIC,
         CAP(NAME(TP))+" tries to climb the wall but fails due to "
         "missing skills.\n");
      msg_write(CMSG_GENERIC,
         "Sorry, but climbing there is not possible at the moment.\n");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"In a dimly lit forest.");
   Set(P_INT_WIZMSG,
"This is a dimly lit forest. Right to the southwest is the citywall\
 (maybe someone could leave the city there by climbing over the wall)\n\
 North: a small path to the entrance of the park\n\
 East:  Deeper into the forest.\n");

   Set(P_INT_LONG,
      "This is a small forest. A path comes leads in from the north "
      "and continues to the east deeper into the forest. To the "
      "southwest you see the citywall.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("climb",#'climb_wall /*'*/);

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-160,80,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("north",  SIL_PARK("forest_room2"));
   AddExit("east",   SIL_PARK("forest_room4"));
}
