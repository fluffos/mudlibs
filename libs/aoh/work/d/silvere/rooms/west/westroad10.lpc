// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added regions/coordinates
//                Auryn    [22-May-1999]  description, details


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
#include <macros.h>

inherit SILBASEROOM;

int go_south()
{
  switch(({int})TO->Query(P_DAY_STATE))
       {
       case ND_SUNRISE..ND_SUNSET: // 3..9
	 {
      write("You enter the flower shop.\n");
      TP->move(SIL_WEST("flowershop"),M_GO,"south");
      break;
	 }

       default:
	 write("The shop is closed for the night. Come back after "
	       "sunrise.\n");
	 break;
       }
     return 1;
}

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

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westway");
   Set(P_INT_LONG,
"The house south of you looks remarkable, standing out even among the "
"colourfully painted buildings of Westway. A wrought-iron sign is hanging "
"above the door. @@TimeMsg@@. East, you see the palace, an impressive "
"white marble building. Far off to the west lies the harbour of Silvere.\n");

   Set(P_INT_WIZMSG,
 "WEST:  to the harbour and the temple of Xalandre.\n\
  EAST:  to the palace and the center of the city.\n\
  SOUTH: the flower shop.\n");


   Set(P_TIME_MSG,
       ([ DAY_DEFAULT_MSG: "Brightly dressed people bustle around everywhere, "
       "going about their daily business. They create an infernal noise, "
       "making you wonder how anyone could actually live here",
       NIGHT_DEFAULT_MSG: "The street lies empty, all the shops are "
       "closed for the night. Everything is silent",
       ND_SUNRISE: "People start emerging from the houses, getting ready "
       "for a new day's business. The shops are opened",
       ND_SUNSET: "As the suns sets, the shops are closed and the street "
       "starts to get empty"
	]) );

AddVItem(
	 ([P_IDS:({"house","shop","front","house front","shop front" }),
       P_ADS: ({"remarkable"}),
       P_LONG: "The shop's front is painted snow white and decorated with "
       "hundreds of red and pink roses. The flowers have obviously been "
       "painted by a talented artist, for they look stunningly real. The door "
       "is painted pink, too. A sign is fixed above it.\n"
      ]) );

AddVItem(
	 ([ P_IDS: ({"roses","flowers"}),
	 P_ADS: ({"red","pink"}),
	 P_LONG: "The roses adorning the shop front look almost real.\n"
	 ]) );

AddDetail("door","The shop's door is painted bright pink. A sign hangs "
"above it.\n");

AddVItem(
	 ([ P_IDS: ({"buildings","houses","shops"}),
	 P_ADS: ({"painted","colourful","colourfully painted"}),
	 P_LONG: "The houses along Westway are all painted in bright colours, "
	 "showing off the wealth of their owners. The shop south of you, "
	 "however, is decorated richly enough to stand out even among them.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"sign","rose"}),
	 P_ADS: ({"iron","metal","wrought-iron"}),
	 P_LONG: "An iron rose hangs above the shop door, its petals "
	 "just opening. The sign is a very fine piece of work, looking "
	 "like a real rose in every detail.",
	 P_READ_MSG: "There is nothing written on the sign. It just looks "
	 "like a rose, indicating that the building contains a flower shop.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"palace","building"}),
	 P_ADS: ({"impressive","white","marble"}),
	 P_LONG:"The palace of the Lu'meyn rises east of you. It is built "
	 "from snow white marble and really large. From where you are "
	 "standing, you cannot make out any further details.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"marble"}),
	 P_ADS: ({"finest","white","snow white"}),
	 P_LONG:"Only the finest white marble was used to build the palace.\n"
	  ]) );

AddDetail( ({"street","westway"}),"Westway is a broad street leading from "
"the palace to the harbour. During daytime, it is brimming with life, as "
"many fine shops can be found along it.\n");

AddDetail("harbour","It lies far to the west, much too far for you to see "
"anything from here.\n");


   Set(P_INT_SMELL, "A faint fragrance emanates from the shop south "
   "of you. It smells of flowers in full bloom, though you cannot make "
   "out what kinds - there are too many different scents mingling here.\n");

   Set(P_INT_NOISE, SF(CheckNoise));

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -90,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

AddExit("west",   SIL_WEST("westroad9"));
AddExit("east",   SIL_WEST("westroad11"));
AddExit("south",  SF(go_south));
}

