// This is a small road, that leads to a sell-only shop
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westroad");
   Set(P_INT_LONG,
"This is a small road, that leads from the mainroad to the south.\
 The mysterious Caves of Parch are located to the west.\
 To the south is a small shop, that only sells item.\n");
   Set(P_INT_WIZMSG,
" SOUTH: enter a small shop.\n\
 NORTH: back to the mainroad.\n\
 WEST: enter the beginning of the Caves of Parch.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -150,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("west",   SIL_WEST("cparch"));
   AddExit("south",  SIL_WEST("westshop"));
   AddExit("north",  SIL_WEST("westshop1"));
}
