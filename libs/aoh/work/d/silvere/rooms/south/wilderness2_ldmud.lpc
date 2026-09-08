// The mainroad to the southgates
// created:       Sonic    [10-Aug-1997] layout/region/coordinates
// last changed:

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <macros.h>
inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road at Silvere");
   Set(P_INT_LONG,
      "This is a road leading north to south. To the north is the city "
      "of Silvere. To the south is a bridge leading over the river. A "
      "small path leads there before the bridge to the west through the "
      "fields.\n");

   Set(P_INT_WIZMSG,
" North: to the city of Silvere.\n"
" South: to the forest, over the bridge.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,180,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("wilderness1"));
   AddExit("south",   SIL_SOUTH("wilderness2"));
}
