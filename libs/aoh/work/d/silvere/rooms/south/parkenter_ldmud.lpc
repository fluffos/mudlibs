// The entrance to the citypark, right now just a void place
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [19-Jun-1997]
//                Sonic    [05-Jul-1997] added regions/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road at Silvere");
   Set(P_INT_LONG,
"This is a small road, leading from the citypark to the west into\
 the city of Silvere. The buildings to the north and south are somewhat "
"foggy, as if someone hasn't decided yet, how they should look like or "
"what can be found there.\n");

   Set(P_INT_WIZMSG,
" West: back to the citypark.\n"
" East: to the mainroad of the city.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({-70,140,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",   SIL_PARK("southentrance"));
   AddExit("east",   SIL_SOUTH("parkroad6"));
}
