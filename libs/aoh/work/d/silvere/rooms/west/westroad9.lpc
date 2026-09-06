// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997] Added regions/coordinates
//                Auryn    [21-May-1999] description, details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
#include <macros.h>

inherit SILBASEROOM;

string CheckNoise()
{
  switch (({int})TO->Query(P_DAY_STATE))
    {
    case ND_SUNRISE: return // 3
		       "You hear the sounds of shutters opening. Somewhere, "
		       "a bird sings.\n";
    break;
    case ND_SUNSET: return // 9
		      "Slowly the noise around you dims a bit as the street "
		      "gets emptier.\n";
    break;
    case ND_EARLY_MORNING..ND_LATE_AFTERNOON: return // 4..8
		   "The noise is awful. Everybody seems to be shouting at "
		   "the top of their lungs. You feel slightly dizzy.\n";
    break;
    case ND_NIGHT..ND_DAWN:
    case ND_TWILIGHT..ND_EVENING: return
		     "Everything is silent.\n";
    break;
    }
    return 0;
}

string CheckShutters()
{
  switch (({int})TO->Query(P_DAY_STATE))
    {
    case ND_SUNRISE..ND_SUNSET: return // 3..9
				  "They are open.\n";
    break;
    case ND_NIGHT..ND_DAWN:  // 0..2
    case ND_TWILIGHT..ND_EVENING: return // 10..2
				 "They are closed.\n";
    break;
    }
    return 0;
}

string CheckShops()
{
  switch (({int})TO->Query(P_DAY_STATE))
    {
    case ND_SUNRISE: return // 3
		       "As the sun rises, the shops are opened.\n";
    break;
    case ND_SUNSET: return // 9
		      "As the sun sets, the shops are closed and shuttered "
		      "for the night.\n";
    break;
    case ND_EARLY_MORNING..ND_LATE_AFTERNOON: return // 4..8
		  "The shops are open, and business is in full swing. "
		  "Perhaps you feel like going on a shopping tour yourself?\n";
    break;
    case ND_NIGHT..ND_DAWN: // 0..2
    case ND_TWILIGHT..ND_EVENING: return // 10..11
		     "The shops are closed, their shutters down and locked "
		     "securely for the night.\n";
    break;
    }
    return 0;
}

string CheckMerchants()
{
  switch (({int})TO->Query(P_DAY_STATE))
    {
    case ND_SUNRISE: return // 3
		       "You see the merchants opening their shops, getting "
		       "ready for another day of business.\n";
    break;
    case ND_SUNSET: return // 9
		      "You see the merchants closing their shops for the "
		      "night, then retreat inside to count their day's "
		      "earnings.\n";
    break;
    case ND_EARLY_MORNING..ND_LATE_AFTERNOON: return // 4..8
		   "Most of the merchants are in their shops right now, and "
		   "those you see on the street seem to be on some urgent "
		   "business.\n";
    break;
    case ND_NIGHT..ND_DAWN: // 0..2
    case ND_TWILIGHT..ND_EVENING: return // 10..11
		     "You don't see any. It is night, after all.\n";
    break;
    }
    return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westway. A street leads south");
   Set(P_INT_LONG,
"A street branches off Westway here, leading south. East of you, you can "
"see the palace in the distance. Brightly painted houses line Westway, "
"indicating that this is one of the better quarters of the city. @@TimeMsg@@\n"
);

   Set(P_INT_WIZMSG,
 "WEST:  to the harbour and the temple of Xalandre.\n\
 EAST:  deeper into the city.\n\
 SOUTH: to the library and the guild\n");


   Set(P_TIME_MSG,
       ([ DAY_DEFAULT_MSG:"The shops on their ground floors are open. "
       "Business seems to be good today, judging from the many people who "
       "are milling about everywhere, creating an infernal noise.",
       NIGHT_DEFAULT_MSG:"The shops are closed for the night, and everything "
       "is quiet. During daytime, however, this is one of the busiest parts "
       "of Silvere.",
       ND_SUNRISE:"As the first rays of the sun illumine the new day, the "
       "merchants open their shops, ready for business.",
       ND_SUNSET:"With the last light of the sinking sun, the merchants "
       "close their shops. The streets start to empty, and the noise around "
       "you slowly dims to a more tolerable level."
	]) );


AddDetail("palace","From here, you cannot make out more than the silhouette "
	  "of the palace. Go east if you want a closer look.\n");

AddDetail("merchants",SF(CheckMerchants));

AddDetail("street","South of you starts Guild Street. As its name implies, it "
	  "leads to the Adventurers' Guild. The library of Silvere can also "
	  "be found somewhere along it.\n");

AddDetail("westway","Westway leads from the palace to the harbour. Along "
"its length, some of the finest shops in Silvere can be found. The large "
"flagstones it has been paved with are always swept clean and kept in "
"excellent repair.\n");

AddDetail("shops",SF(CheckShops));


AddDetail("shutters",SF(CheckShutters));

AddDetail("library","You remember someone telling you the library was "
"somewhere along Guild Street, but you can't see it from here.\n");

AddDetail("silhouette","The silhouette of the palace can be seen to the east. "
"However, you are still too far off to make out any details.\n");

AddDetail("houses","Painted in every colour imaginable, the houses along "
"Westway are a splendid sight. Their owners must be quite wealthy to be able "
"to afford them.\n");

AddVItem(
	 ([ P_IDS: ({"stones","flagstones"}),
	 P_ADS: ({"large","smooth"}),
	 P_LONG: "Westway has been paved with large, smooth flagstones. They "
	 "are swept every day.\n"
	  ]) );

Set(P_INT_NOISE,SF(CheckNoise));
Set(P_INT_SMELL,
    "The wind brings a smell of salt and seaweed from the ocean.\n");


   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -100,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("south",  SIL_WEST("libraryroad1"));
   AddExit("west",   SIL_WEST("westroad8"));
   AddExit("east",   SIL_WEST("westroad10"));
}

