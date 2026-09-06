// A broad road, that leads to the Council Hall.
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Auryn    [14-Jun-1999]  description, details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Elrimand Road, leading to the council hall");
   Set(P_INT_LONG,
"A warm scent of freshly baked bread wafts from the house west of you. "
"A sign above the door proclaims it a bakery. Elrimand Road leads north "
"towards the council hall. South of you is the main street of this part of "
"Silvere, Westway, @@TimeMsg@@.\n");

   Set(P_INT_WIZMSG,
" NORTH: To the council hall.\n\
 SOUTH: To the main road\n\
 WEST: The bakery\n");

   Set(P_TIME_MSG,
       ([ DAY_DEFAULT_MSG: "which seems to be throbbing with life as lots "
       "of people bustle to and fro on their various errands.",
       NIGHT_DEFAULT_MSG: "which for once lies silent under the starry "
       "sky.",
       ND_SUNRISE: "where the shops are just being opened for a new day "
       "of trade and business.",
       ND_SUNSET: "which slowly empties as the sun sets. Better hurry up if "
       "you still have some shopping to do today!"
	]) );

   AddDetail( ({"scent","warm scent"}),"Just smell... \n");
   AddDetail( ({"house","bakery"}),"The bakery's front is painted bright "
   "yellow, with a snow white door. A sign formed like a pretzel hangs "
   "above the entrance.\n");

   AddVItem(
	    ([ P_IDS: ({"door","entrance"}),
	    P_ADS: ({"white","snow white"}),
	    P_LONG: "The bakery's white door is spotless. A sign is hanging "
	    "above it.\n"
	     ]) );

   AddVItem(
	    ([ P_IDS: ({"sign","pretzel"}),
       P_ADS: ({"large","wooden"}),
	    P_LONG: "The wooden sign above the door is formed like a large "
	    "pretzel. Something is written on it in neat letters.\n",
	    P_READ_MSG: "'Eldranna's Bake Shoppe'\n"
	     ]) );

   AddDetail( ({"letters","neat letters"}),"Why not read the sign, since "
   "somebody obviously took the trouble to put the letters on it?\n");

   AddDetail( ({"road","elrimand road"}),"A broad street leading north. It "
   "was named after the founder of Silvere.\n");

   AddDetail( ({"street","main street","westway"}),
	      "Westway is the main business district of Silvere. It is "
	      "south of you.\n");

   Set(P_INT_SMELL, "The air smells of freshly baked bread and other "
       "delicious things, making your mouth water.\n");
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -120,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("north",  SIL_WEST("councilroad2"));
   AddExit("south",  SIL_WEST("westroad7"));
   AddExit("west",   SIL_WEST("bakery"));
}
