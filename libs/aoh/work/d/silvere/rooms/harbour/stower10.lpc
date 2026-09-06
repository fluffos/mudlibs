// on top of the tower. A catapult is standing here
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
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On the tower");
   Set(P_INT_LONG,
"A catapult stands here, pointing on the open sea. Two men are\
 standing here, watching out of the sea. To the east is a small\
 shelter from the sun.\n\
East:  To a shelter\n\
North: To the platform and the stairs\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,30,20 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("north",SIL_HARBOUR("stower9"));
   AddExit("east", SIL_HARBOUR("stower11"));
}
