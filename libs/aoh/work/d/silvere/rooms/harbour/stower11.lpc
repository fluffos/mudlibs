// on top of the tower. A small shelter is here
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
"This is a shelter on top of the tower. It is used by the watch\
 crew. Two men are standing guard, two men are staying here, exchanging\
 each other from time to time. To the north is a mirror, to the west\
 is the catapult.\n\
West:  To the catapult\n\
North: To a mirror.\n");

   /*
    * Add details here *giggle*
    */

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,30,20 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into the battlements.\n");
   AddExit("north",SIL_HARBOUR("stower12"));
   AddExit("west", SIL_HARBOUR("stower10"));
}
