// The wedding chapel of Silvere, part of the Temple of Xalandre
// Idea: Chara
// created:          Sonic    [25-Sep-1997] basic layout
// changed:          not yet  [enter date]

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <macros.h>
inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Xalandre's Chapel");
   Set(P_INT_LONG,
      "The temple of Xalandre, northern part. Weddings take place "
      "here.\n");

   Set(P_INT_WIZMSG,
" SOUTH:  Back to the temple.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -150,-20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("south",   SIL_WEST("xal_temple"));
}
