// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [29-Jun-1997] Coordinates added
//                Sonic    [01-Jul-1997] Regions added
//                Joan     [20-Oct-1997] added some details and sounds

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
inherit SILBASEROOM;

string QueryIntNoise()
{
  string *tmp;

  tmp = ({
   "The noise of the city rudely intrudes upon the peace "
   "of the quiet avenue.\n",
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
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"The palace avenue");
   Set(P_INT_LONG,
"The east side of the wide palace avenue boasts graceful "
"lime trees as it continues gentley to the north and south. "
"The west side of the avenue boasts a myriad of soft "
"blue Arabellas and a neat row of delicate tiny cassia cinnamon "
"trees hugging the east palace wall. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" South: To the west and southpart of Silvere, the palace, etc.\n"
" North: to the east part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue gently continues north and "
   "south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"flower","flowers","arabellas","arabella",
   "blue arabella","blue arabellas"}),"A myriad of soft blue  "
   "Arabellas hug the base of the tiny trees and palace wall.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"cinnamon","cinnamon trees","cassia cinnamon",
   "cassia cinnamon tree","cassia cinnamon trees","cinnamon trees",
   "cinnamons"}),"Beautiful tiny cinnamons line the base of the "
   "the brownstone palace wall. Their heady scent makes you "
   "think of home, your mother and cinnamon bread.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"jays","mocking birds","jay","mocking bird",}),
   "Noisy jays and mocking birds chase each other through "
   "the trees.\n");

   SetIntSmell("You are delighted with the clean fresh scent "
   "of ripening limes and heady smell of cinnamon.\n");



   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Seagulls glide silently high over head. Mourning "
       "doves coo as they forage though the soft grass "
       "under the trees.\n",
     NIGHT_DEFAULT_MSG:
       "Gay light from the palace spills across the avenue "
       "and trees. Gently swaying with the breeze, the trees "
       "cast long dancing shadows upon the dark stone road.\n"]));


   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 50,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

   AddExit("north", SIL_CENTER("outside16"));
   AddExit("south", SIL_CENTER("outside14"));
}
