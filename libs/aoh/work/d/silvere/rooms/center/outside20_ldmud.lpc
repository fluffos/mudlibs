// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates
// changed:       Joan     [16-Oct-1997]  added some details
// changed:       Joan     [12-Dec-1997]  added southwest exit

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
   "A frog croaks a mournful tune somewhere in the distance.\n ",
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
"Lime trees border the wide palace avenue as it gently turns "
"to the west and to the south. To the southwest a small grove "
"of sweet pomegranates grows between the main building and "
"the west wing of the palace. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
"To the southwest is a small, unused place, where something can be "
"placed, if someone has an idea. Right now is just a little group "
"of trees\n"
" South:  to the east and south part of Silvere and other places.\n"
" West: the road around the palace, to the west part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue gently curving to the west and "
   "south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime tree","lime trees","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"grove","pomegranate tree","pomegranate trees"}),
   "Just to your southeast is a small grove os sweet pomegranate "
   "trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

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
       "Jays and mocking birds chase each other through "
       "the trees as seagulls float lazily high overhead.\n",
     NIGHT_DEFAULT_MSG:
       "Dim light from the palace reaches this far corner of the "
       "road throwing the trees into deep shadow.\n"]));

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 50,-20,0 }), C_SILVERE }) );


   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

   AddExit("west",  SIL_CENTER("outside21"));
   AddExit("southwest", SIL_CENTER("garden4"));
   AddExit("south", SIL_CENTER("outside19"));
}
