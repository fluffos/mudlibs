// This is a small road, that leads toward the temple to the northeast
// created:       Sonic    [29-May-1997]
// last changed:  Chara    [7-June-1997]
//                Sonic    [01-Jul-1997]  Added region/coordinates

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
    "A small but well-worn path leads north towards the Temple of Xalandre. "
    "Xalandre is the goddess of the sea, and the patron goddess of "
    "Silvere.\n");

   AddDetail( ({"road", "path"}),
    "The dirt path winds charmingly to the north.  Although it is not "
    "very large, it seems to have been worn smooth by the passage of "
    "many feet.\n");

   Set(P_INT_WIZMSG,
" SOUTH: back to the main road.\n\
 NORTH: to the temple entrance.\n");

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -170,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
    "It is better to stay on the road.\n");
   AddExit("south",  SIL_WEST("westroad2"));
   AddExit("north",  SIL_WEST("templeroad2"));
}
