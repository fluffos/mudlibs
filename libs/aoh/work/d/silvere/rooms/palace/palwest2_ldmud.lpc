// Some room inside the palace
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
   Set(P_INT_SHORT,"A hall in the palace");
   Set(P_INT_LONG,
"A high passage leads in from the east and continues to the north and "
"south. Ceremonial guards are standing at the walls and seems to glance "
"at you.The walls are full with tapestries and such stuff and every now "
"and then there is a decorative item placed on a small podestal.\n");

   Set(P_INT_WIZMSG,
" East:  throneroom, east wing, exit.\n"
" North: private rooms of the Lu'meyn, west wing of the palace.\n"
" South: walk around in the western wing of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -20,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("east",  SIL_PALACE("palwest1"));
   AddExit("north", SIL_PALACE("palwest3"));
   AddExit("south", SIL_PALACE("palwest13"));
}
