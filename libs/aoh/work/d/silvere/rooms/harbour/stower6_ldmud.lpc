// Inside the tower. The waiting room of the crew.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates

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
"This is the waiting room for the crew of the tower. Maybe do a\
 card game or something else... To the south are the stairs down\
 and to the west is the platform and the stairs up.\n\
West:  To the stairs up and the platform\n\
South: To the stairs downwards\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,20,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("south",SIL_HARBOUR("stower5"));
   AddExit("west", SIL_HARBOUR("stower7"));
}
