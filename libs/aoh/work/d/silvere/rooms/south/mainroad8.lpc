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
"This is a broad road, leading from north to south. To the south is "
"the citygate, to the north is the palace of the king. The buildings "
"to the left and right seems to be somewhat foggy, as if they are not "
"really here.\n");

   Set(P_INT_WIZMSG,
" North: back to the palace-area.\n"
" South: to the southern citygate.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,120,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("mainroad7"));
   AddExit("south",   SIL_SOUTH("mainroad9"));
}
