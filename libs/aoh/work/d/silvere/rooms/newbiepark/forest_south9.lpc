// A small path, leading northwest to the cats.
// created:       Sonic    [15-Jun-1997]
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
   Set(P_INT_SHORT,"on a path in the forest");
   Set(P_INT_WIZMSG,
"This is a small path in the forest, which leads from north to south.\
 Nothing spectacular here.\n\
 North: Deeper into the forest, to some encounters.\n\
 South: To the exit of the park.\n");

   Set(P_INT_LONG,
      "This is a small path, leading from north to the south. All "
      "around the path are growing trees and bushes. There is a "
      "wall to the east, made out of the backsides of some buildings.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-90,130,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("north", SIL_PARK("forest_south7"));
   AddExit("south", SIL_PARK("forest_south10"));
}
