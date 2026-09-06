// The mainroad to the southgates
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [19-Jun-1997]
//                Sonic    [05-Jul-1997]  added regions/coordinates

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
"This is a broad road, leading from the palace to the north toward the "
"gates of the city to the south. The buildings to the left and right "
"seems to be somewhat foggy, as if they are not really here.\n");

   Set(P_INT_WIZMSG,
" North: back to the palace-area.\n"
" South: to the southern citygate.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,50,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_CENTER("mainsouth1"));
   AddExit("south",   SIL_SOUTH("mainroad2"));
}
