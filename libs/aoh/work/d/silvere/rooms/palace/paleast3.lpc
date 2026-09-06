// The entrance to the palace...
// created:       Sonic    [08-Jul-1997]
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
"A high passage leads from north to south. There is also another way to "
"the east. Ceremonial guards are standing at the walls and seems to glance "
" at you.The walls are full with tapestries and such stuff and every now "
"and then there is a decorative item placed on a small podestal.\n");

   Set(P_INT_WIZMSG,
" East:  to some rooms in the east wing of the palace.\n"
" North: private rooms of the Lu'meyn,\n"
" South: walk around in the eastern wing of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 20,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("east",  SIL_PALACE("paleast4"));
   AddExit("north", SIL_PALACE("palnorth1"));
   AddExit("south", SIL_PALACE("paleast2"));
}
