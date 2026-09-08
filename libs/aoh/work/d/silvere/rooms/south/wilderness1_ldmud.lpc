// The mainroad to the southgates
// created:       Sonic    [10-Aug-1997] layout, region/coordinates
// last changed:

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
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
      "To the north are the gates of Silvere. A broad road "
      "leads there to the south toward a bridge over the river. "
      "To the south is also a small crossing, where a path leads "
      "to the west through some fields.\n");

   Set(P_INT_WIZMSG,
" North: to the city of Silvere.\n"
" South: to a bridge leading over the river.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,170,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("southgate"));
   AddExit("south",   SIL_SOUTH("wilderness1"));
}
