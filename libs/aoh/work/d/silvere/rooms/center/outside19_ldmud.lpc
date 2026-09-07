// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [29-Jun-1997] Coordinates added
// changed:       Sonic    [01-Jul-1997] Regions added
// changed:       Joan     [16-Oct-1997] added random and time sounds
// changed:       Joan     [12-Dec-1997] added west exit

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
   "A frog croaks a mournful tune somewhere in the distance.\n",
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
"Lime trees border the wide palace avenue as it gracefully "
"continues to the north and south. To the west a small grove "
"of sweet pomegranates grows between the main building and "
"the west wing of the palace. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
"To the west is a small, unused place, where something can be "
"placed, if someone has an idea. Right now is just a little group "
"of trees\n"
" South: to the South part of Silvere and other places.\n"
" North: the road around the palace, to the west part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue as it gently continues north and "
   "south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");


   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"grove","pomegranate tree","pomegranate trees"}),
   "Just to your southwest is a small grove of sweet pomegranate"
   "trees.\n");

   AddDetail( ({"pomegranates","pomegranate"}),"You can't see "
   "them from here.\n");


   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"jays","mocking birds","jay","mocking bird",}),
   "Noisy jays and mocking birds chase each other through "
   "the trees.\n");

   SetIntSmell("You are delighted with the clean fresh scent "
   "of ripening limes.\n");



   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Seagulls glide silently high over head.\n",
     NIGHT_DEFAULT_MSG:
       "Light from the palace softly illuminates the avenue and "
       "trees causing the trees to throw sharp shadows across "
       "the avenue.\n"]));

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 50,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

   AddExit("north", SIL_CENTER("outside20"));
   AddExit("west", SIL_CENTER("garden4"));
   AddExit("south", SIL_CENTER("outside18"));
}
