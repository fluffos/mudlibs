// The mainroad to the southgates
// created:       Sonic    [19-Jun-1997]
// last changed:  Sonic [05-Jul-1997] added region/coordinates

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
"The citygates of Silvere are right to the south. To the north you can "
"go to the palace and there is also a crossing, where you can reach the "
"citypark.\n");

   Set(P_INT_WIZMSG,
" North: to the citypark, deeper into the city.\n"
" South: to the southern citygate.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,150,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("mainroad10"));
   AddExit("south",   SIL_SOUTH("southgate"));
}
