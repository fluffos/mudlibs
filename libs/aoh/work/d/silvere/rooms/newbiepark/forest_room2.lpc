// This is the forest, which contains the newbie monsters
// created:       Sonic    [06-Jun-1997]
// last changed:  Sonic    [02-Jul-1997]  added region/coordinates

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
   Set(P_INT_SHORT,"In a dimly lit forest");
   Set(P_INT_WIZMSG,
"This is somewhere in a small, but pleasant forest.\n\
 North: a small path to the entrance of the park\n\
 South: Deeper into the forest.\n");

   Set(P_INT_LONG,
      "This is a small forest. A path comes in from the north and "
      "leads to the south deeper into the forest.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_FOREST | REGION_CITY);
   Set(P_COORDINATES, ({ ({-160,70,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("north",  SIL_PARK("forest_room1"));
   AddExit("south",  SIL_PARK("forest_room3"));
}
