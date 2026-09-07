// A small road, that leads to a smith.
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997] Added regions/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"small road");
   Set(P_INT_LONG,
"This is a small road, that leads from east to west. To the east\
 the road leads into a shop. To the west is a crossing, where the\
 road leads from north to south.\n");
   Set(P_INT_WIZMSG,
" WEST: back to the crossing.\n\
 EAST:  the way to the weaponsmith.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -140,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");
   AddExit("east",   SIL_WEST("wsmithroad2"));
   AddExit("west",   SIL_WEST("westshop1"));
}
