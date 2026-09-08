// The mainroad to the southgates
// created:       Sonic    [10-Aug-1997] layout, region/coordinates
// last changed:

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit SILBASEROOM;

int prevent_south()
{
   msg_write(CMSG_GENERIC,
"The area to the south of the city is not done yet. "
"Eilan plans to do a forest there and Tune wants to add a "
"river and a lighthouse at the coast. Please be more patient.\n");
   return 1;
}

varargs void create()
{
   (::create());
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road south");
   Set(P_INT_LONG,
      "This is a road leading to the south. To the north is the city "
      "of Silvere. You see also a small crossing to the north, where a "
      "small path leads to the west through some fields. To the south "
      "is a bridge leading over the river. *No details yet, room only "
      "layouted.\n");

   Set(P_INT_WIZMSG,
" North: to the city of Silvere.\n"
" South: to the forest over the river. (to be added)\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,200,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("wilderness3"));
// * the rooms to the south are unfinished and not uploaded yet.
// * the function is there to prevent errors, just in case some
// * curious people wanders around and hit a not-yet-existing
// * room :-)
//   AddExit("south",   SIL_SOUTH("bridge1"));
   AddExit("south",   #'prevent_south /*'*/);
}
