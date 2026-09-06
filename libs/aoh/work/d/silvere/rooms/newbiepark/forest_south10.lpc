// A crossing: from the south entrance to the snake pit and to the north
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
   Set(P_INT_SHORT,"Border of the forest");
   Set(P_INT_WIZMSG,
"The path leads from east to the north. There are some bushes, but "
"an opening leads to the west into a snakepit (two rooms). Directly "
"to the east are the gates to the southern part of Silvere.\n\
 North: Deeper into the forest, to some encounters.\n\
 East:  Leave the park to the city of Silvere.\n\
 West:  Enter the snakepit.\n");

   Set(P_INT_LONG,
      "The path leads in from the gates to the east deeper into the "
      "forest to the north. To the west are some bushes with a hole, "
      "where you could fit through.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-90,140,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("north",  SIL_PARK("forest_south9"));
   AddExit("east",   SIL_PARK("southentrance"));
   AddExit("west",   SIL_PARK("snake_pit1"));
}
