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
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"A hall in the palace");
   Set(P_INT_LONG,
"A high passage leads in from the south and continues to the west. There "
"you see two doors, leading there through the southern wall. Ceremonial "
"guards are standing here at the wall and look in full attention at you, "
"just as they have to protect something very valuable. The guards clothes "
"is also slightly changed from the guards to the south. To the south is "
"a small crossing, where another passage leads in from the east.\n");

   Set(P_INT_WIZMSG,
" West:  To the private rooms of the king and queen.\n"
" South: To the throneroom and the eastern/western part of the palace.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 20,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",   SIL_PALACE("palnorth2"));
   AddExit("south",  SIL_PALACE("paleast3"));
}
