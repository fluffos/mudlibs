// The mainroad from the palace to the southern citygates.
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates
//                Tune     [13-jul-1997]  more description/stuff
// changed:       Joan     [04-Sept-2001] Added stuff


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <config.h>
#include <macros.h>
#include <nightday.h>

inherit SILBASEROOM;

#define SOAK  15

string QueryIntNoise()
{
  string *tmp;

  tmp = ({
   "A distant shout from the city reaches your ears.\n",
   "The clickety clack coach of wheels intrude into palace solitude.\n",
   "You hear a horse clip clop along in the distance.\n",
   "A chapel bell rings in the distance.\n",
   "The wind whispers echos of the sad story of Xalandre's "
   "lost love...\n",

  });

  if( ({int})NIGHTDAY->IsDay() )
    tmp += ({
      "Jays gaily chatter and mourning doves coo while mocking "
      "birds scold you for coming to near.\n"
      });

  else
    tmp += ({
      "Cicadas and crickets chirp merry night symphonies all around "
      "you.\n",
      "An owl calls out from somewhere in the trees.\n"
    });
   return random_select(tmp);

}

varargs void create()
{
   ::create();

   Set(P_INT_SHORT,"The palace square");
   Set(P_INT_LONG,
    "This is a small paved square nestled between two wings of the "
    "palace. Off to the east and west you can see beds of exotic flowers "
    "artfully arranged in geometric designs beneath the palace windows. "
    "A carved fountain graces the center of the square, gurgling quietly "
    "as water splashes into a large basin. @@TimeMsg@@\n"
   );

   Set(P_INT_WIZMSG,
    " North: The entrance into the palace.\n"
    " South: The mainroad toward the southern gates of Silvere.\n"
    " West:  To the walls of the west wing of the palace.\n"
    " East:  To the walls of the east wing of the palace.\n");

   AddDetail("palace",
    "The Royal Palace of Silvere. Great, ain't it?\n");// TODO !

   AddVItem(
    ([ P_IDS : ({ "fountain" }),
       P_ADS: ({ "pearly", "carved", "white", "stone" }),
       P_LONG :
        "The fountain seems to have been carved from a single block of some "
        "pearly white stone. A large, low basin catches the falling water, "
        "which pours out from the mouths of 4 carved griffins standing in the "
        "basin, each pointing towards one of the cardinal points of the "
        "compass.\n"
    ]) );

   AddDetail( "pearly carved white stone",
    "The white stone gleams and glistens under the moisture.\n");

   AddDetail("pearly white stone basin",
    "A low, round pool rests upon the ground to catch the tumbling "
    "showers of the fountain. It was carved from the same pearly stone "
    "as the four griffins.\n");

   AddVItem(
    ([ P_IDS: ({ "griffins", "griffons" }), // both sp. are correct
       P_ADS: ({ "white", "stone" }),
       P_LONG:
      "The griffins stand in ready alertness above the fountain's basin; "
      "four proud eagles' heads poised high, four regal lions' bodies "
      "pointed outwards in the four cardinal directions. Water spurts "
      "from their open mouths, cascading into the basin below.\n"
    ]) );

   AddDetail(({ "falling water","waters" }),
    "The gurgling water looks clean and safe to drink.\n");

   AddDetail("paving stones",
    "The paving stones of the square are smaller in size than those "
    "generally used on the streets of Silvere. Stones of light and "
    "dark hues have been arranged to form the image of a sunburst "
    "around the basin of the fountain.\n");

   AddDetail("flower beds",
    "The flower beds are laid out in intricate, geometric designs "
    "and feature perfect specimens of the brightest, most radiant "
    "blossoms the realm has to offer.\n");

   AddVItem(
    ([ P_IDS: ({ "patterns", "designs" }),
       P_ADS: ({ "flower", "geometric", "intricate" }),
       P_LONG:
        "The bright patterns of flowers makes looping scrolls of color, "
        "a veritable feast of hues and textures.\n",
    ]) );

   AddVItem(
    ([ P_IDS : ({ "flowers", "blossoms", "blooms" }),
       P_ADS : ({ "vibrant", "radiant", "exotic" }),
       P_LONG : ({
        "The royal gardeners labor to keep the most exotic, "
        "most fragrant and most radiant blooms in the gardens and "
        "parks around the palace for the pleasure of the Lu'meyn.\n",
        "TODO!\n"
	  }),
       P_SMELL : "The fragrant softness tickles your nose pleasantly.\n",
    ]) );

   Set(P_INT_NOISE,
    "The tumbling waters of the glistening stone fountain bubble and "
    "gurgle softly as they spring from the open mouths of the carved "
    "griffins.\n");

   AddNoise(({ "water", "fountain", "waters" }),
    "The tumbling waters of the glistening stone fountain bubble and "
    "gurgle softly as they spring from the open mouths of the carved "
    "griffins. Legend has it that the waters of the fountain sometimes "
    "whisper the tale of Xalandre's lost love to those who listen "
    "carefully.\n");

SetIntSmell("The flowers fill the air with their delicate "
   "perfume. The sweet smell of the water tinkling in the fountain draws your attention to it.\n");

Set(P_TIME_MSG,
    ([ NIGHT_DEFAULT_MSG:
       "Cast iron lanterns with alabaster sides glow softly, casting a soft "
       "glow onto the paths through the foliage. Six alabaster lanterns  "
       "illuminate the fountain with their soft glow. ",
             DAY_DEFAULT_MSG:
       "The sunlight plays off the cascading waters, making rippling "
       "shadows on the paving stones of the square.\n"
    ]) );

   Set(P_REFILL, "water");

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,30,0 }), C_SILVERE }) );
   Set(P_INDOORS, 0);

   AddRoomCmd("drink", "cmd_drink");

   AddExit("south", SIL_CENTER("mainsouth1"));
   AddExit("north", SIL_CENTER("palplace5"));
   AddExit("east",  SIL_CENTER("palplace3"));
   AddExit("west",  SIL_CENTER("palplace1"));
}

int cmd_drink(string str)
{
  if(!str)
  {
    notify_fail("Drink what?\n");
    return 0;
  }

  if(str != "water" && str != "water from fountain" && str != "from fountain")
  {
    notify_fail("Drink what from what?\n");
    return 0;
  }

  if (({int})TP->QueryDrink()+ SOAK > ({int})TP->QueryMaxDrink())
  {
    notify_fail("You can't drink that much.\n", NOTIFY_NOT_VALID);
    return 0;
  }

  TP->AddDrink(SOAK);
  write("You quench your thirst with the clear, cold water.\n");
  say(CAP(NAME(TP))+" drinks from the fountain.\n");
  return 1;
}
