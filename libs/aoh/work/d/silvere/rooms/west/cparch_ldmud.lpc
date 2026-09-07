// Caves of Parch
// created:    SuperJ [Now, when was the date?]

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
   Set(P_INT_SHORT,"Caves of Parch");
   Set(P_INT_LONG,
"This is the entrance to the Caves of Parch.  Long ago, according\
 to legend, an ancient magical creature named Parch dwelt in\
 these caves, guarding incomprehensible riches of mythical\
 proportions.  Currently, the cave entrance is blocked.\n");
   Set(P_INT_WIZMSG,
" EAST:  Back out there. \n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);

   Set(P_NOWAY_MSG,
"You run silly around. Somehow you have the feeling, that everyone laughs\
 at you.\n");
   AddExit("east",   SIL_WEST("westshop2"));
}
