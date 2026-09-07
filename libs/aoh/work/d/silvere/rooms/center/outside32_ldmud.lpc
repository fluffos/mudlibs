// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates
//                Joan     [29-Oct-1997]  added some details

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
   "You hear the soft cooing sounds of the mourning doves over "
   "the loud cawing of the gulls.\n",
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
   Set(P_INT_SHORT,"palace avenue");
   Set(P_INT_LONG,
"Elegant lime trees border the west side of the north to south "
"length of avenue while the brownstones of the west wing palace "
"wall border the east side. To the south the avenue gracefully "
"intersects with a crossing to the west. To the east delicate "
"cinnamon trees and exotic jasmine border the west palace wall. "
"@@TimeMsg@@\n");


   Set(P_INT_WIZMSG,
" North: to the north part of Silvere and other places.\n"
" South: the road around the palace, to the west part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue gently continues north and "
   "south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"jasmine","flowers","flower"}),"Small well tended "
   "jasmine shrubs are covered with beautiful white and yellow "
   "star shaped flowers. The scent is so heavenly you are tempted "
   "to lay here for awhile.\n");

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

   SetIntSmell("The clean fresh scent of ripening limes mingles "
   "with the heady smell of cinnamon bark, while jasmine perfumes "
   "the air with its special scent.\n");


   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Seagulls glide silently high over head. Mourning doves "
       "coo as they forage though the soft grass under the "
       "trees.\n",
     NIGHT_DEFAULT_MSG:
       "Gay light from the palace spills across the avenue "
       "and trees. Gently swaying with the breeze, the trees "
       "cast long dancing shadows upon the dark stone road.\n"]));


   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -50,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree an idiot. Somehow you have the feeling that "
"everyone laughs at you.\n");

   AddExit("south", SIL_CENTER("outside2"));
   AddExit("north", SIL_CENTER("outside31"));
}
