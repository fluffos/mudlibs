// A room in the western wing of the palace
// created:       Sonic    [21-Jul-1997]
// last changed:

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A room in the palace");
   Set(P_INT_LONG,
"This is a large room. Lots of decorations on the wall, but no guards "
"anymore. Tapestries and pedestals with lots of items are standing there. "
"Nothing is planned yet. Make that a conference room, a dining hall, a "
"strategie-room or something else.\n");

   Set(P_INT_WIZMSG,
" North: Leave that room and enter the west wing of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -30,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north", SIL_PALACE("palwest4"));
}
