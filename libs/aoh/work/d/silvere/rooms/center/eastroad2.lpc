// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [30-Jun-1997] added coordinates/regions

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
   Set(P_INT_SHORT,"Mainroad leading east");
   Set(P_INT_LONG,
"This is a broad road, that leads from east to west. To the west is "
"the palace of Silvere, where you can see a road leading from north "
"to south. To the east you can reach the buildings of the eastern "
"district of Silvere.\n");

   Set(P_INT_WIZMSG,
" West: back to the palace and the center of the city.\n"
" East: enter the eastern part of the city.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 70,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",   SIL_CENTER("eastroad1"));
   AddExit("east",   SIL_EAST("mainroad1"));
}
