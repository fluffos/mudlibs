// on top of the tower. At a mirror
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
"Before a mirror. The mirror is used to exchange messages between the\
 tower by light signals. It can be moved to the east and north. Before\
 the mirror is also a place for a big fire, when the sun is not shining.\
 To the south is the shelter, to the west is the platform and the stairs.\n\
West:  To the platform and the stairs down\n\
South: To the shelter.\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,20,20 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("south",SIL_HARBOUR("stower11"));
   AddExit("west", SIL_HARBOUR("stower9"));
}
