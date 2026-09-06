// The private rooms of the Lu'meyna
// created:       Sonic    [21-Jul-1997]
// last changed:

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <doors.h>
inherit BASEROOM;
inherit "/std/door";

varargs void create()
{
   room::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"the room of the Lu'meyna");
   Set(P_INT_LONG,
"This are the private rooms of the Lu'meyna. No idea, what to do... ;-)\n");
   Set(P_INT_WIZMSG,
" North: Back to the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 10,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddDoor("north", SIL_PALACE("palnorth2"),
            ([ P_DOORCODE:"wooden door",
               P_SHORT:"a wooden door",
               P_LONG:
                  "This is a wooden door, that leads to the north. "
                  "On the door are some intricate carvings, laid in "
                  "with gold and silver.\n",
               P_SUB_DETAILS:
               ([ ({"carving","carvings","intricate carvings"}):
                  "The carvings can be found on the door. They are just "
                  "some patterns in the door, that are laid in with gold "
                  "and silver. It looks very nice.\n",
                  ({ "gold","silver"}):
                  "No, you can't take that.\n",
                  ({ "pattern","patterns"}):
                  "The pattern is carved into the door. The carvings "
                  "was then filled again with some gold and silver.\n",
               ]),
               P_HIDEEXIT:HIDE_ALWAYS,
               P_LOCKSTATE:LOCK_CLOSED,
            ]) );
}
