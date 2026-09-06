// The mainroad to the southgates
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997] Added region/coordinates
//                Mistral  [05-Sep-1997] Connected house to the south

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road at Silvere");
   Set(P_INT_LONG,
"This is a broad road, leading from the palace to the west toward the "
"gates of the city to the east. The buildings to the left and right "
"seems to be somewhat foggy, as if they are not really here. "
"To the south is the house of Joan and Mistral.\n");

   Set(P_INT_WIZMSG,
" West: back to the palace-area.\n"
 " East: to the eastern citygate (unfinished).\n"
"South: the house of Joan and Mistral (maybe way to Xanadu some day).\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 80,10,0}), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",   SIL_CENTER("eastroad2"));
AddExit("south","/d/silvere/rooms/east/mistralhouse/garden1");
}
