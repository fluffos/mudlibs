// A little crossing. To the north are some rats and rabbits, to the
// east you can find some rabbits. The cats and dogs are to the south
// created:       Sonic    [07-Jun-1997]
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
"This is a crossing in the forest. To the northwest is a crossing,\
 where you can reach the rats. To the east are the rabbits. Another\
 road leads southwest to the cats and dogs section :-)\n\
 Northwest: The path leads here to the northern exit of the park.\n\
 Southwest: There you can find the cats and dogs.\n\
 East:      You want to slay some wabbits? Then go there.\n");

   Set(P_INT_LONG,
      "This is a crossing in the forest. A path leads in from the east, "
      "where you see some movement. The path continues to the north- "
      "and southwest.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-130,90,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("east",      SIL_PARK("forest_room7"));
   AddExit("northwest", SIL_PARK("forest_room5"));
   AddExit("southwest", SIL_PARK("forest_south1"));
}
