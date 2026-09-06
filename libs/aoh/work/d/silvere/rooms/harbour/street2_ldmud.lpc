// This is a simple street to connect the harbour with the city-gates
// created:          Sonic  [26-May-1997]
// last changed      Sonic  [05-Jul-1997] added region/coordinates
//                   Taurec [14-Oct-1997] added improved roomdesc.

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit HARBOUR_BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"A street");
   Set(P_INT_LONG,
     "This is a small paved road that meanders gently down to the "
     "harbour of Silvere. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
    "East: City-Gates, Harbourmaster, Inn\n"
    "West: the docking areas.\n");

   AddDetail("road",
     "A small paved street, covered with sand from the surrounding "
     "dunes.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -220,10,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run in a wall.\n");
   AddExit("east",SIL_HARBOUR("street1"));
   AddExit("west",SIL_HARBOUR("street3"));

   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Up the hill to the east are the city gates, the shining armour of "
       "the patrolling guards up there glitters brightly. The ocean "
       "of Shamyra opens to the west and you've got a great view upon "
       "the little bay down there. Busy shipping is going on all over "
       "the harbour basin.",
     NIGHT_DEFAULT_MSG:
       "Up the hill to the east, you see some torchlight dance up and "
       "down. This must be the guards patrolling the city gates. Westwards, "
       "however, you can hear the distant roar of the Sea of Shamyra. "
       "A glittering chain of tiny lights draws the outline of the bay "
       "down there."
    ]));
}
