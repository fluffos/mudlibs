// This is the forest, which contains the newbie monsters
// created:       Sonic    [06-Jun-1997]
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
"This is a dimly lit forest. To the east is an area with some rats, cats\
 and some few rabbits. (At the map, the northern circle).\n\
 West:  The path leads here to the northern exit of the park.\n\
 East:  This leads deeper into the forest and to the southexit.\n");

   Set(P_INT_LONG,
      "This is a small forest. A path comes leads in from the west "
      "and continues to the east deeper into the forest. There is "
      "a crossing to the east, where the path leads to the northeast "
      "and southeast.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-150,80,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west",   SIL_PARK("forest_room3"));
   AddExit("east",   SIL_PARK("forest_room5"));
}
