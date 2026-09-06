/**
 **    The base room for the harbour at Silvere.
 **    created:          Tune   [29-May-1997]
 **    last changed:     Mica   [04-Jun-1997]
 **                      Taurec [05-Jan-1998]
 **                      Tune   [10-May-1998]  fixed bug in smell & noise
 **
 **    Includes:
 **       random smell & listen msgs
 **       Std details for the harbour area
 **       horizon detail based on time of day
 **       special time msgs for harbour area
 **/

#include <silvere.h>
#include <properties.h>
#include <nightday.h>
#include <weather.h>
#include <moving.h>
#include <rooms.h>
inherit BASEROOM;

string look_horizon();
string look_sun();
string look_towers();
string look_ships();
string look_battleships();
string look_ocean();

public varargs void create(int repl)
{
   ::create();

   Set(P_INDOORS,0);

   AddDetail("bay",
    "The small bay opens west out to the sea. The city of "
    "Silvere lies to the east of the water. The opening of the bay "
    "is guarded by two tall defense towers, one on each side.\n");

   AddDetail("harbour",
    "The small harbour lies well-protected within the small bay, "
    "guarded at the open end by two tall defense towers. Though the "
    "harbour is small, it is deep enough for ocean-going vessels to "
    "dock with ease.\n");

   AddDetail( ({ "city", "silvere" }),
    "The lovely city of Silvere lies directly east of the harbour.\n");

   AddDetail( ({ "quay", "quays" }),
    "Two quays, one to the north of the harbour, and the other to the "
    "south, facilitate the loading and unloading of ships. At the end "
    "of each quay stands a defense tower.\n");

   AddDetail("horizon", #'look_horizon /*'*/);
   AddDetail( "sun",    #'look_sun /*'*/);
   AddDetail(({"tower","towers"}), #'look_towers /*'*/);
   AddDetail("ships", #'look_ships /*'*/);
   AddDetail(({"battleships","battleship"}), #'look_battleships /*'*/);
   AddDetail(({"sea","sea of shamyra","ocean","ocean of shamyra"}),#'look_ocean /*'*/);

   AddVItem(
   ([ P_IDS:({"water"}),
      P_ADS:({"murky"}),
      P_SMELL:
         "Puh, that's awful. Seems that something dead or rotten "
         "swims there...\n",
      P_LONG:
         "The water of the harbour is really not the cleanest. "
         "And the smell from it is awful too.\n",
   ]) );
}

string QueryIntNoise()
{
  string *tmp;
  string rc;

  rc = ::QueryIntNoise();
  if (stringp(rc) || closurep(rc))
    return rc;

  tmp = ({
   "The sound of seals barking in the distance floats over the water.\n",
   "The waves lap quietly at the quays.\n",
   "Fishermen call out greetings to each other from their boats.\n",
   "Ropes creak as the waves tug at boats moored in the bay.\n",
   "Old wooden docks bump lightly against each other.\n",
   "You can hear waves crashing on a distant beach.\n",
   "The wind whispers echos of the sad story of Xalandre's lost love...\n"
  });

  return tmp[random(sizeof(tmp))];
}

string QueryIntSmell()
{
  string *tmp;
  string rc;

  rc = ::QueryIntSmell();
  if (stringp(rc) || closurep(rc))
    return rc;

  tmp = ({
   "Briney sea salt tingles your nostrils.\n",
   "Stale fish odors hang in the air.\n",
   "The pungent odor of dead seaweed assaults your nostrils.\n",
   "Briney sea salt and stale fish odors hang in the air.\n",
   "The fresh sea breeze smells invigorating.\n"
  });
  return tmp[random(sizeof(tmp))];
}

mixed *FilterWeatherData(object client, mixed *data, int newstate)
{
  switch(newstate)
  {
    case ND_NIGHT:

      data[WD_DESC] =
       "The deep blackness of night is broken only by the twinkling "
       "of thousands of stars reflected from the dark waves.\n";
      data[WD_CDESC] =
       "The last glow of the sun slips beneath the horizon, and "
       "darkness blankets the land.\n";
      break;

    case ND_PREDAWN:

      data[WD_DESC] =
       "A faint golden glow hangs low in the dark night sky.\n";
      data[WD_CDESC] =
       "A faint golden glow begins to build in the eastern sky.\n";
      break;

    case ND_DAWN:

      data[WD_DESC] =
       "The towers of Silvere gleam, outlined in silver halos, as the"
       "glow of the rising sun fills the eastern sky.\n";
      data[WD_CDESC] =
       "The towers of Silvere are haloed with a rosy golden glow as "
       "the sun slowly rises from behind the city.\n";
      break;


    case ND_SUNRISE:
      data[WD_CDESC] =
       "The fires on top of the harbour towers are extinguished as the sun "
       "welcomes a new day.\n";
      break;

    //case ND_EARLY_MORNING:
      //data[WD_CDESC]

    // case ND_LATE_MORNING:
      //data[WD_CDESC]

    //case ND_NOON:
      //data[WD_CDESC]

    //case ND_EARLY_AFTERNOON:
      //data[WD_CDESC]

    // case ND_LATE_AFTERNOON:

    case ND_SUNSET:
      data[WD_CDESC] =
       "The firey red sun slowly dips beneath the edge of the sea. The "
       "fires on top of the two towers are lit to mark the harbour "
       "entrance.\n";
      break;

    case ND_TWILIGHT:
      data[WD_CDESC] =
      "A golden glow shimmers in the darkness above the silvery edge of the sea.\n";

    case ND_EVENING:
      data[WD_CDESC] =
       "Only a golden glow hangs above the now darkened horizon, "
       "marking where the sun disappeared over the edge of the ocean.\n";
  }
  return data;
}

/*
** -------------------------------------------------------
** The sun varies during day too... at least the position
** does.
*/
string look_sun()
{
   switch(({int})NIGHTDAY->Query(P_STATE))
   {
      case ND_PREDAWN:
      case ND_DAWN:
         return
            "A faint glow appears at the eastern horizon. The sun is "
            "not visible, though.\n";
         break;
      case ND_SUNRISE:
         return
            "The sun just appeared on the eastern horizon and makes"
            "the view of the city of Silvere just awesome. It proves "
            "once again that nature creates wonders every day.\n";
         break;
      case ND_EARLY_MORNING:
         return
            "The sun stands above the city of Silvere. It shines down "
            "from the sky, lighting the harbour.\n";
         break;
      case ND_LATE_MORNING:
         return
            "The sun stands high on the sky above Silvere and shines "
            "down at you.\n";
         break;
      case ND_NOON:
         return
            "The sun seems to stand directly above you on the sky. It "
            "burns down, lighting everything.\n";
         break;
      case ND_EARLY_AFTERNOON:
         return
            "The sun stands high on the sky beyond the towers and "
            "shines down at you.\n";
         break;
      case ND_LATE_AFTERNOON:
         return
            "The sun stands on the sky, somewhere behind the towers. "
            "They are casting long shadows over the whole harbour.\n";
         break;
      case ND_SUNSET:
         return
            "The sun touches the western horizon and fills the sea "
            "with an red glow. It somehow seems that the whole sea "
            "is made out of blood.\n";
         break;
      case ND_TWILIGHT:
         return
            "The sun isn't visible anymore. Out on the sea of Shamyra "
            "is a faint glow of red filling the horizon.\n";
         break;
      default: return 0; break;
   }
   return 0;
}

/* -------------------------------------------------------
 **  The horizon varies depending on the time of day
 **/

string look_horizon()
{
  switch(({int})NIGHTDAY->Query(P_STATE))
  {
    case ND_NIGHT:
      return "The endless black of the churning sea reflects the "
             "light of the stars.\n";
      break;
    case ND_PREDAWN:
      return "A faint line divides the blackness of the sea from the grey of the "
             "heavens.\n";
      break;
    case ND_DAWN:  /* fall through */
    case ND_SUNRISE:
      return "The horizon becomes more distinct as the sky lightens with "
             "morning's arrival.\n";
      break;
    case ND_EARLY_MORNING:
    case ND_LATE_MORNING:
      return "The sharp edge of the horizon sparkles in the early morning light.\n";
      break;
    case ND_NOON:
      return "A spectacular view accross azure waves straight into infinity.\n";
      break;
    case ND_EARLY_AFTERNOON:
    case ND_LATE_AFTERNOON:
      return "The lengthening afternoon shadows play accross the water.\n";
      break;
    case ND_SUNSET:
      return "A spectacular display of red and gold streams out over the horizon.\n";
      break;
    case ND_TWILIGHT:
      return "A reddish glow on the horizon marks where the sun has disappeared.\n";
      break;
    case ND_EVENING:
      return "Strata of red and purple hang over the quickly darkening horizon.\n";
      break;
    default:
      return "The horizon stretches endlessly out beyond the waves.\n";
  }
  return "The horizon stretches endlessly out beyond the waves.\n";
}

/* -------------------------------------------------------
 **  The towers and ships vary depending on the time of day
 **/

string look_towers()
{
  if (({int})NIGHTDAY->IsDay()) return
   "These strongly fortified towers look like two massive guardians, "
   "watching the entrance to the harbour attentively. No movement between "
   "them stays unnoticed. Nothing can hide from their sharp glance.\n";
  else return
   "You make out the dark outlines of the two towers guarding "
   "the harbour entrance. On top of each there is a bright fire to "
   "guide the ships into the harbour at night without risking damage "
   "to their hulls on a shallow area.\n";
}

string look_ships()
{
  if (({int})NIGHTDAY->IsDay()) return
   "There are mostly fisherboats to be seen in the harbour. "
   "Besides those, there are some huge battleships of Lu'meyns mighty "
   "fleet. Several passenger ships enter and leave the harbour.\n";
  else return
   "It's so dark out there in the harbour basin and you can't "
   "make out much. You can only see black and grey silhouettes of "
   "unidentified ships rolling gently up and down on the waves.\n";
}

string look_battleships()
{
  if (({int})NIGHTDAY->IsDay()) return
   "This is the royal fleet of Silvere, several proud battle"
   "ships that have cast anchor here. They all show the signs of "
   "Lu'meyn, and the flags flutter in the breeze, showing the blue "
   "and white sigil of the four griffins.\n";
  else return 0;
}

string look_ocean()
{
  if (({int})NIGHTDAY->IsDay()) return
   "The sea of Shamyra - source of many tales and sages - "
   "lies just outside the bay with the harbour "
   "of Silvere. It continues to the horizon, where it seems to melt "
   "into the sky. It's a astonishing view from here.\n";
  else return
   "Somewhere in the dark west of you, you sense the sea of "
   "Shamyra. A fresh breeze ruffles your hair, filled with the "
   "scent of salt and seaweed. Lost out there on the sea, there are "
   "little spots of light many miles away from the coast, the lights "
   "of ships that did not make their way home in time.\n";
}
