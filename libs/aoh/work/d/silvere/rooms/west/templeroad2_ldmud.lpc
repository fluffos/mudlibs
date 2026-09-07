// This is a small road, that leads toward the temple to the northeast
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added regions/coordinates

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
   Set(P_INT_SHORT,"Templeroad");
   Set(P_INT_LONG,
"This is a small road, that leads in from the south and continues\
 east toward the temple of Xalandre.\n");
   Set(P_INT_WIZMSG,
" SOUTH: back to the main road.\n\
 EAST:  to the temple entrance.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -170,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("south",  SIL_WEST("templeroad1"));
   AddExit("east",   SIL_WEST("templeroad3"));
}
