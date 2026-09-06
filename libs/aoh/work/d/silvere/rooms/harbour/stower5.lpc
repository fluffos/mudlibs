// Inside the tower. Stairs leading down
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
"This is a room in the tower, where a stair leads down to the basement.\
 To the west is a storeroom with stones for the catapults. To the north\
 is a waiting room for the crew.\n\
Down:  Stairs to the basement.\n\
West:  To the storeroom with ammo for the catapults\n\
North: To a waiting room for the crew.\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,30,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("west", SIL_HARBOUR("stower8"));
   AddExit("north",SIL_HARBOUR("stower6"));
   AddExit("down", SIL_HARBOUR("stower3"));
}
