// The road from the mainroad to the citypark
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
"This is a small road from a crossing to the east toward the citypark. "
"The buildings to the north and south are somewhat foggy, as if someone "
"didn't decide yet, how they should look like or what to be found there. ");

   Set(P_INT_WIZMSG,
" West:  to the citypark.\n"
" East:  to the mainroad.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({-20,140,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("east",   SIL_SOUTH("parkroad1"));
   AddExit("west",   SIL_SOUTH("parkroad3"));
}
