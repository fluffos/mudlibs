// The mainroad to the southgates
// created:       Sonic    [10-Aug-1997]  layout/region/coordinates
// last changed:

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <macros.h>
inherit SILBASEROOM;

int prevent_west()
{
   notify_fail(
      "The path to the west through the fields is not finished yet. "
      "So it is a good idea to wait and check another time, when "
      "one of that lazy wizards of OSB has done that rooms and added "
      "them to the world.\n", NOTIFY_ILL_ARG);
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road at Silvere");
   Set(P_INT_LONG,
      "This is a road leading north to south. To the north is the city "
      "of Silvere. To the south is a bridge leading over the river. A "
      "small path leads to the west through the fields. In the distance "
      "you can see a windmill.\n");

   Set(P_INT_WIZMSG,
" North: to the city of Silvere.\n"
" South: to the forest, over the bridge.\n"
" West:  to the fields including a windmill and the lighthouse.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,190,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("wilderness2"));
   AddExit("south",   SIL_SOUTH("rivershore1"));
// * the rooms to the west are unfinished and not uploaded yet.
// * the function is there to prevent errors, just in case some
// * curious people wanders around and hit a not-yet-existing
// * room :-)
// AddExit("west",   SIL_FIELDS("fieldroad1"));
   AddExit("west",   SF(prevent_west));
}
