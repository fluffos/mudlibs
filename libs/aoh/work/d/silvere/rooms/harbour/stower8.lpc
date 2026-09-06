// Inside the tower. A storeroom with ammo for the catapults.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added region/coordinates

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
"This is a storeroom. Large piles of boulders can be found here. (Of course\
 they are way to heavy to taken by a single person). An exit leads north\
 toward a platform, where the stones are moved upwards to be loaded into\
 the catapults.\n\
East:  To the stair, which are leading down.\n\
North: To a platform, leading up\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,30,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("north",SIL_HARBOUR("stower7"));
   AddExit("east", SIL_HARBOUR("stower5"));
}
