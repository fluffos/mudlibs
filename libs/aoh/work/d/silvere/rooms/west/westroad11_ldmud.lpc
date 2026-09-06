// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added region/coordinates
//                Auryn    [31-May-1999]  description, details

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
    case ND_NIGHT..ND_DAWN: // 10..2
    case ND_TWILIGHT..ND_EVENING: return // 10..2
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
    default: return "It is night, and nobody is on the street, except for a "
	       "few guards of the Night Watch.\n";
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
"Westway widens here and opens into a large square to the east. There you "
"see a large marble building: the palace of the Lu'meyn, which lies at the "
"center of the city. To the west, the street runs towards the harbour, "
"passing some of Silvere's finest shops on the way. @@TimeMsg@@ \n");

   Set(P_INT_WIZMSG,
" WEST:  to the harbour and the temple of Xalandre.\n\
 EAST:  to the palace and the center of the city.\n");

   Set(P_TIME_MSG,
       ([ DAY_DEFAULT_MSG: "It is day, and lots of people are bustling "
       "around everywhere. This close to the palace, there are more "
       "guards than elsewhere along the street. Everyone seems to be "
       "very busy.",
       NIGHT_DEFAULT_MSG: "It is night, and the street is empty save for "
       "some guards. This close to the palace, patrols are more frequent "
       "than elsewhere in the city.",
       ND_SUNRISE: "As the sun rises, the street starts to fill with people "
       "who get ready for their day's work. The night patrol of the City "
       "Guard is just being relieved by the day shift.",
       ND_SUNSET: "As the sun sets, the street starts to empty. You see the "
       "guards on patrol being relieved by the Night Watch."
	]) );

AddVItem(
	 ([ P_IDS: ({"street","westway","boulevard"}),
	 P_ADS: ({"wide","broad"}),
	 P_LONG: "Westway is a broad street running from the palace to the "
	 "harbour. It is paved with large flagstones. The houses along the "
	 "street are painted in bright, friendly colours, and most of them "
	 "have intricate decorations. As most of the houses are owned by rich "
	 "merchants, many of them have shops on the ground floor.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"palace","building"}),
	 P_ADS: ({"large","impressive","marble","white"}),
	 P_LONG: "The palace is an impressive structure built entirely from "
	 "snow white marble. When the sun is shining, it gleams so brightly "
	 "it is hard to look at its walls, and at night it seems to glow "
	 "softly in the moonlight. The palace is one of the most beautiful "
	 "buildings in Silvere. Also, the gardens surrounding it are famous "
	 "throughout the land. If you go east, you can have a closer look "
	 "at them, and at the palace as well.\n"
	  ]) );

AddDetail("harbour","The harbour is much too far away to be seen.\n");

AddVItem(
	 ([ P_IDS: ({"flagstones","stones"}),
	 P_ADS: ({"large","smooth"}),
	 P_LONG: "Westway is paved with large, smooth flagstones, which "
	 "are carefully swept every day.\n"
	  ]) );
AddVItem(
	 ([ P_IDS: ({"houses","buildings","fronts"}),
	 P_LONG: "The houses along Westway clearly belong to the well-to-do. "
	 "Only wealthy citizens can afford to live along Silvere's finest "
	 "boulevard. The houses' fronts are painted in every colour "
	 "imaginable, and most of them are decorated with intricate "
	 "ornaments.\n"
	  ]) );
AddVItem(
	 ([ P_IDS: ({"colour","colours","hues","shades"}),
	 P_ADS: ({"bright","friendly"}),
	 P_LONG: "Loking down Westway is like looking at a rainbow, for the "
	 "houses lining the street are painted in what must be hundreds of "
	 "different hues and shades. The houses' owners seem to take pride "
	 "in displaying their wealth that way. All those colours lend a "
	 "nice and friendly touch to this part of the city.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"decorations"}),
	 P_ADS: ({"intricate"}),
	 P_LONG: "The houses' fronts are often decorated. Many of them "
	 "show maritime or mythological scenes, but there are also lots "
	 "of abstract ornaments.\n"
	  ]) );

AddVItem(
	([ P_IDS: ({"scenes","scene","pictures","murals"}),
	P_ADS: ({"maritime","mythological"}),
	P_LONG: "The houses are painted with colourful pictures, showing "
	"creatuers of the ocean and scenes from old stories and legends.\n"
	]) );

AddDetail("creatures","The paintings show mermaids, sea dragons, krakens and "
     "many different kinds of fish, all painted in fantastic colours and with "
	"great attention to detail.\n");

AddDetail( ({"mermaids","ocean","rock"}),"One mural shows some mermaids "
"sitting on a rock in the ocean. They seem to be singing. The picture "
"looks so real you think you can almost hear them.\n");

AddDetail( ({"dragons","sea dragons"}),"They almost seem to be alive.\n");

AddDetail( ({"krakens","fish"}), "They are painted so realistically you "
            "almost expect them to swim away any moment.\n");

AddVItem(
	([P_IDS: ({"ornaments","shapes"}),
	P_ADS: ({"abstract","colourful","knotwork","intricate","geometric"}),
	P_LONG: "You see intricate knotwork ornaments as well as geometric "
	"shapes, done in a multitide of colours.\n"
	]) );

AddDetail( ({"stories","legends"}),"Some houses are painted with scenes from "
"old stories. One of them shows Elrimand, the first Lu'meyn of Silvere, "
"planting a tree in front of the council hall.\n");

AddDetail("elrimand","Elrimand was the founder and first ruler of Silvere. "
"The street leading from Westway to the council hall was named in his "
"honour.\n");

AddDetail("tree","Legend has it that Elrimand himself planted a tree in "
"front of the council hall when it was finished. The tree is still there, "
"having grown quite tall over the centuries.\n");

AddDetail( ({"hall","council hall"}),"The hall on the painting is a splendid "
"white building. You can visit the real council hall if you want to know "
"what it looks like today.\n");

AddVItem(
	([P_IDS: ({"marble"}),
	P_ADS: ({"fine","white","snow white"}),
	P_LONG: "The palace is built from fine white marble.\n"
	]) );

AddDetail("square","The square east of you is the centre of Silvere. "
       "The palace of the Lu'meyn is there, as well as the famous gardens.\n");

AddDetail("shops","The shops along Westway are the finest in all of Silvere. "
	"Whatever one might be looking for is probably to be found in one of "
	"them - usually for a steep price.\n");

AddDetail("people", SF(CheckPeople));

   Set(P_INT_SMELL, "The wind brings the smell of salt and seaweed from the "
       "harbour.\n");
   Set(P_INT_NOISE, SF(CheckNoise));
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -80,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("west",   SIL_WEST("westroad10"));
   AddExit("east",   SIL_CENTER("westenter"));
}

