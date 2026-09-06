// on top of the tower. Stairs are leading down.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On the tower");
   Set(P_INT_LONG,
"Stairs are leading down here. A platform is here, where stones are\
 moved from below to load the catapults. To the east is a large\
 mirror, to the south is the catapult.\n\
Down:  To the second level of the tower.\n\
East:  To a mirror...\n\
South: To the catapult\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,20,20 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("down", SIL_HARBOUR("stower7"));
   AddExit("south",SIL_HARBOUR("stower10"));
   AddExit("east", SIL_HARBOUR("stower12"));
}
