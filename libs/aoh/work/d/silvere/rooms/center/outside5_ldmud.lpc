// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [29-Jun-1997] Coordinates added
//                Sonic    [01-Jul-1997] Regions added
//                Joan     [01-Nov-1997] added some details and stuff

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
   "The noise from the city doesn't reach this far along "
   "the palace road and you can hear the birds chattering "
   "happily in the trees.\n",
   "A frog croaks a happy tune somewhere in the distance.\n ",
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
"The palace avenue gracefully turns east and north here. "
"Cinnamon trees to the east and lime trees to the west "
"guard the beautiful bonnie bells in thier soft grass "
"beds by the west palace wall. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" North: Follow the road to the north around the palace.\n"
" East:  Follow the road to the entrance of the palace.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue gently curves north and "
   "east.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"flower","flowers","bonnie bells","bonnies"}),
   "Neat beds of bright purple bonnie bells make a blushing "
   "border for the tiny trees and palace wall. They smell "
   "wonderful!\n");

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
       "Jays and mocking birds chase each other through "
       "the trees as seagulls float lazily high overhead.\n",
     NIGHT_DEFAULT_MSG:
       "Dim light from the palace reaches this are corner of the "
       "road throwing the trees into deep shadow.\n"]));

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -50,40,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

   AddExit("east",  SIL_CENTER("outside6"));
   AddExit("north",  SIL_CENTER("outside4"));

}
