// The entrance to the palace...
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
"A high passage leads from south to west. To the west is also an "
"entrance leading to the south. Ceremonial guards are standing at "
"the walls and seems to glance at you. The walls are full with "
"tapestries and such stuff and every now and then there is a "
"decorative item placed on a small podestal.\n");

   Set(P_INT_WIZMSG,
" West: to the throneroom, the northern/western part of the palace.\n"
" South: passage leading through the eastern part of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 40,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",  SIL_PALACE("paleast4"));
   AddExit("south", SIL_PALACE("paleast7"));
}
