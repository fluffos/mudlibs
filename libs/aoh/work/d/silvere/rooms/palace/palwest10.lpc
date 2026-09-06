// The western part of the palace
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
"A high passage leads here from east to west. Ceremonial guards are "
"standing at the walls and seems to glance at you. The walls are full "
"with tapestries and such stuff and every now and then there is a "
"decorative item placed on a small podestal.\n");

   Set(P_INT_WIZMSG,
" North: there could be a stairway up to some tower, or another room.\n"
" East: to the throneroom, the northern/eastern part of the palace.\n"
" West: passage leading through the western part of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -30,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north", SIL_PALACE("palwest11"));
   AddExit("west",  SIL_PALACE("palwest9"));
   AddExit("east",  SIL_PALACE("palwest12"));
}
