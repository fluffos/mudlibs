// The mainroad to the southgates
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [29-Jun-1997]

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit SILBASEROOM;

int prevent_void()
{
   msg_write(CMSG_GENERIC,
      "Just as you try to walk north, you notice that nothing is real "
      "there. The area to the north is not yet layouted, so maybe you "
      "should come back later.\n");
   return 1;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road at Silvere");
   Set(P_INT_LONG,
"This is a broad road, leading from the backside of the palace to the "
"south toward the gates of the city to the north. The buildings to "
"the left and right seems to be somewhat foggy, as if they are not "
"really here.\n");

   Set(P_INT_WIZMSG,
" South: back to the palace-area.\n"
" North: to the northern part of the town.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,-30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("south",   SIL_CENTER("outside25"));
// just something temporary to avoid errors
   AddExit("north",  #'prevent_void /*'*/);
}
