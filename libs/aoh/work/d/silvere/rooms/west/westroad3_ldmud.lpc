// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  Added regions/coordinates
//                Auryn    [24-Apr-1999]  Changed long, added details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>

inherit SILBASEROOM;

string people_detail()
{
   if( ({int})NIGHTDAY->IsDay() )
   {
      return
       "Hoardes of eager shoppers, sailors on shore leave, merchants "
       "with a cool eye for bargains, all crowd the streets of "
       "Silvere, sampling the rich wares on offer, strolling in the "
       "sunshine, or lost in thought as they hurry away on unknown "
       "errands.\n";
    }
    return
      "The streets are mostly empty, save the odd drunk, staggering home "
      "after a hard night in the tavern. Sensible folk don't wander "
      "about the city at night.\n";
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westway");
   Set(P_INT_LONG,
"This is Westway, in many respects the heart of Silvere. Along this "
"road, much of the business going on in the city is conducted. Shops "
"and houses painted in bright, friendly colours line the street. "
"@@TimeMsg@@ North of you, you see a small shop. The road continues "
"to the east and west.\n");

   Set(P_INT_WIZMSG,
" WEST: to the harbour and the temple of Xalandre.\n\
 EAST: deeper into the city.\n\
 NORTH: the chandler's shop\n");


   AddVItem(
       ([ P_IDS: ({ "road", "street" , "westway" }),
	    P_ADS: ({ "wide", "beautiful" }),
	    P_LONG:
	    "Westway is a wide, beautiful street that runs through the "
	    "city from the harbour east of you to the palace in the west.\n"
	]) );

   AddVItem(
       ([ P_IDS: ({ "shop", "entrance" }),
          P_ADS: ({ "small" }),
          P_LONG:
	  "North of you is the entrance to a small shop. Its front is "
	  "painted a bright yellow. A round sign is fixed above the sturdy "
	  "wooden door.\n"
	]) );

   AddVItem(
	    ([ P_IDS: ({ "door" }),
	    P_ADS: ({ "sturdy", "wooden" }),
	    P_LONG:
	    "The door leads into the small shop north of you. Above "
	    "it hangs a round wooden sign.\n"
	     ]) );

   AddVItem(
	    ([ P_IDS: ({ "sign" }),
	    P_ADS: ({ "round", "wooden" }),
	    P_LONG:
	    "The sign above the shop's entrance has been painted with "
	    "a picture of a burning candle. You are obviously standing "
	    "in front of a chandler's workshop.\n"
	     ]) );
   AddVItem(
	    ([ P_IDS: ({ "shops", "houses" }),
	    P_ADS: ({ "painted" }),
	    P_LONG:
	    "Brightly painted houses line the street. Only the well-to-do "
	    "can afford to live in this part of the city, and "
	    "the houses give evidence of their owners' wealth. Most of "
	    "them are owned by merchants and have a shop on the ground "
	    "floor.\n"
	     ]) );

AddVItem(
 ([ P_IDS: ({ "people" }),
    P_LONG: #'people_detail /*'*/
 ]) );


   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -160,10,0 }), C_SILVERE }) );

   Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG:"It is day, and business seems to be in full swing. "
          "People are milling around everywhere, and there is a general "
          "bustle of activity.",
      NIGHT_DEFAULT_MSG:"It is night. The street is mostly empty, all the "
          "shops are closed and shuttered.",
      ND_SUNSET:"As the sun is setting, the shops are closing for the "
          "night. Around you, everyone seems to be eager to get home, "
          "and the street is slowly getting empty.",
      ND_DAWN:
          "The sun is not yet up, the street is still empty.",
      ND_SUNRISE:
          "As the sun slowly comes up, the first shops are opened. People "
          "start emerging from the houses, filling the street."
   ]) );


   Set(P_NOWAY_MSG,
"You run around stupidly. Somehow you have the feeling that everyone laughs\
 at you.\n");
   AddExit("west",   SIL_WEST("westroad2"));
   AddExit("east",   SIL_WEST("westroad4"));
   AddExit("north",  SIL_WEST("chandler"));
}
