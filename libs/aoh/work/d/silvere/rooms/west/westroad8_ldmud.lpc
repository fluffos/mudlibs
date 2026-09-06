// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Auryn    [20-May-1999]  description, details

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
    case ND_NIGHT..ND_DAWN: // 0..2
    case ND_TWILIGHT..ND_EVENING: return // 10..11
		     "Everything is silent.\n";
    break;
    }
    return 0;
}


string CheckPeople()
{
  switch (({int})TO->Query(P_DAY_STATE))
    {
    case ND_SUNRISE..ND_SUNSET: return
	 "Brightly dressed people move about on their business everywhere "
	 "around you.\n";
    break;
    default: return "It is night, and nobody is on the street.\n";
      break;
    }
    return "It is night, and nobody is on the street.\n";
}

string CheckVines()
{
   switch(({int})NIGHTDAY->QuerySeason())
   {
      case WINTER: return
         "The vines are brown and leafless.\n";
         break;
      case SPRING: return
         "The first tender green leaves are showing on the vines.\n";
         break;
      case SUMMER: return
         "Dark green leaves cover the vines.\n";
         break;
      case AUTUMN: return
         "The leaves seem to glow in the colours of autumn: yellow, "
	 "golden orange and deep red. They look very pretty.\n";
         break;
   }
   return 0;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westway. North is a wine merchant's shop");
   Set(P_INT_LONG,
"The houses lining the street are painted in bright colours, competing in "
"splendour with the attire of their owners who are milling around busily "
"during daytime. Everybody who is of any importance among Silvere's "
"merchants owns a shop somewhere along Westway. This close to the palace, "
"the shops are getting even more fancy (and more expensive, of course). "
"North of you is the entrance to a small, but very exclusive wine shop. "
"@@TimeMsg@@ \n"
);

   Set(P_INT_WIZMSG,
"WEST: to the harbour and the temple of Xalandre.\n\
 EAST: deeper into the city.\n\
 NORTH: the new wine shop\n");

   /* Time Messages */

   Set(P_TIME_MSG,
       ([ DAY_DEFAULT_MSG: "The street is throbbing with life. All around "
       "you, people are buying, selling and hurrying around. Everyone "
       "seems to be very busy. The noise almost gives you a headache.",
       NIGHT_DEFAULT_MSG: "The street is empty, all the shops closed and "
       "shuttered for the night.",
       ND_SUNSET: "As the last rays of the setting sun light the street, "
       "the merchants close their shops. The street slowly empties.",
       ND_SUNRISE: "With the first sunlight, the shops are opened. People "
       "emerge from the houses, and the street slowly fills with life."
	]) );

   /*Details and VItems */

AddDetail("houses","The houses are brightly coloured and obviously belong "
	  "to rather wealthy people. Most of them have shops on the ground "
	  "floor.\n");

AddDetail( ({"street","boulevard"}),"This is Westway, a broad boulevard "
             "leading from the palace to the harbour.\n");

AddDetail("shops","Most houses have shops on the ground floor. Whatever "
	  "you might be looking for, chances are you will find it along "
	  "Westway.\n");

AddDetail("colours","During daytime, the street is a virtual pandemonium "
	  "of colours and noise.\n");

AddDetail("palace","You can't see it very well from here, go east for a "
	  "better look.\n");

AddVItem(
	 ([ P_IDS: ({"shop","wine shop","house"}),
	 P_ADS: ({"small","exclusive"}),
	 P_LONG: "The house north of you is painted rusty brown. Vines "
	 "grow beside the door, and a sign is fixed above it.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"vine","vines","leaves"}),
	 P_LONG: SF(CheckVines)
	  ]) );

AddDetail("door","The door of the wine shop is painted dark green. A sign "
	  "hangs above it.\n");

AddVItem(
	 ([ P_IDS: ({"sign"}),
	 P_LONG: "The sign shows a picture of a wine glass filled with "
	 "some red liquor.\n",
	 P_READ_MSG: "There is nothing written on the sign, just the "
	 "picture.\n"
	 ]) );

AddDetail( ({"picture","glass","wine glass","liquor","red liquor"}),
	   "The picture looks quite realistic.\n");

AddVItem(
	 ([ P_IDS: ({"owners","people","attire"}),
	 P_LONG: SF(CheckPeople)
	 ]) );

   /* The noise varies depending on the time of day... */

   Set(P_INT_NOISE, SF(CheckNoise));

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -110,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("west",   SIL_WEST("westroad7"));
   AddExit("east",   SIL_WEST("westroad9"));
   AddExit("north",  SIL_WEST("wineshop"));
}

