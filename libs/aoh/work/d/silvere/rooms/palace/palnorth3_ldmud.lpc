// Some room inside the palace
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
   room::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A hall in the palace");
   Set(P_INT_LONG,
"A high passage continues from east to west. Two guards are standing "
"to the left and right of it, protecting the room against unwanted "
"guests. Ceremonial guards are standing here at the wall and look in "
"full attention at you, just as they have to protect something very "
"valuable to them.\n");

   Set(P_INT_WIZMSG,
" East:  To the eastern part of the palace, private room of the Lu'meyna.\n"
" West:  To the western part of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",  SIL_PALACE("palnorth4"));
   AddExit("east",  SIL_PALACE("palnorth2"));
}
