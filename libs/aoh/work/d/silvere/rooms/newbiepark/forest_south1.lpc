// This is a little crossing. To the northeast you can find some rabbits,
// to the southeast are some bigger creatures (dogs or cats)
// created:       Sonic    [14-Jun-1997]
// last changed:  Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"In a dimly lit forest.");
   Set(P_INT_WIZMSG,
"This is a small path in the forest. To the northeast is a small\
 crossing. The road leads here along the citywall to the southeast.\
 Cats or dogs will be available to the south for killing.\n\
 Northeast: The path leads there to the northern exit of the park.\n\
 Southeast: There you can find the cats and dogs.\n");

   Set(P_INT_LONG,
      "This is a small path through the forest. Directly to the west "
      "is the wall of the city. Some bushes are growing at the base "
      "of the wall.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-140,100,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("northeast", SIL_PARK("forest_room6"));
   AddExit("southeast", SIL_PARK("forest_south2"));
}
