// A broad road, that leads to the Council Hall.
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Auryn    [20-Jun-1999]  description, details

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
   Set(P_INT_SHORT,"Elrimand Road");
   Set(P_INT_LONG,
"The street bends here, leading south towards Westway and east to the "
"council hall. The houses left and right of you seem to be the residences "
"of wealthy citizens. @@TimeMsg@@ \n"

);

 Set(P_INT_WIZMSG,
" EAST:  To the council hall.\n\
 SOUTH: To the main road\n");

 Set(P_TIME_MSG,
     ([ DAY_DEFAULT_MSG: "Although it is day, this part of the street is "
     "rather quiet, compared to the bustle of activity further south.",
     NIGHT_DEFAULT_MSG: "It is night, and the street is empty."
      ]) );

 AddDetail( ({"street","road","elrimand road"}),
	   "Elrimand Road is a broad street paved with flagstones. "
	   "To live here, you'd have to have lots of money or influence, "
	   "presumably both. Everything looks neat and clean, and guards "
	   "are frequently patrolling the street to prevent any trouble.\n");

 AddDetail( ({"stones","flagstones"}),
		"They are quite smooth and very clean. City workers sweep "
		"them every day.\n");

 AddDetail("westway","Follow Elrimand Road south and you'll get there.\n");

 AddDetail( ({"hall","council hall"}), "You're still too far away to see "
 "anything.\n");

 AddDetail("guards","They are patrolling the street. Better don't make any "
	   "trouble, they really look tough.\n");

 AddDetail( ({"houses","residences"}),
	    "The houses along Elrimand Road obviously belong to the upper "
	    "crust of Silvere. They are painted in lively colours and "
	    "decorated fancifully, although with a tad more elegance than "
	    "the ones along Westway. Some of them even have a coat of arms "
	    "above the entrance, indicating that someone really important "
	    "lives here.\n");

 AddDetail( ({"colours","lively colours"}),
	    "The houses are painted brightly, but somewhat less garishly "
	    "than some of those along Westway.\n");

 AddDetail( ({"arms","coat of arms","shields","emblems"}),
	    "Shields bearing house emblems have been fixed above the "
	    "entrance of some houses.\n");

 AddDetail( ({"entrance","entrances"}),
	    "The entrances leading into the houses look sturdy and well "
	    "protected. Some of them are decorated with emblems of noble "
	    "houses of Silvere.\n");



   Set(P_INT_SMELL, "The wind carries a faint smell of salt and seaweed from "
       "the harbour.\n");
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -120,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("east",   SIL_WEST("councilroad3"));
   AddExit("south",  SIL_WEST("councilroad1"));
}
