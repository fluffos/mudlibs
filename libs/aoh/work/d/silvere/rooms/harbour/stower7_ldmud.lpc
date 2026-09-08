// Inside the tower. A platform and stairs, which leads up to the top
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
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"in the tower");
   Set(P_INT_LONG,
"Stairs are leading up to the top of the tower. A platform is here, which\
 is used to transport the boulders up to the catapults. To the south is\
 the storeroom, to the east is a waiting room.\n\
Up:    To the top of the tower\n\
East:  To the crew waiting room\n\
South: To the storeroom\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,20,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("up",   SIL_HARBOUR("stower9"));
   AddExit("south",SIL_HARBOUR("stower8"));
   AddExit("east", SIL_HARBOUR("stower6"));
}
