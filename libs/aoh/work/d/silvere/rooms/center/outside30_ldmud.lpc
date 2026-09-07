// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
// last changed:  Joan     [10-Oct-1997]  added some details
// last changed:  Joan     [16-Oct-1997]  added random and time sounds
// last changed:  Joan     [25-Nov-1997]  added exit to garden

#include <nightday.h>
#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
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
   "A frog croaks a tune somewhere in the distance.\n ",
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
   (::create());
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"The palace avenue");
   Set(P_INT_LONG,
"Lime trees border the wide palace avenue as it gently turns "
"to the east and to the south. To the southeast a small grove "
"of fig trees, bordered by a tiny hedge, grows between the main "
"building and the west wing of the palace. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" Southeast: a tiny fig garden.\n"
" East:  to the east and north part of Silvere and other places.\n"
" South: the road around the palace, to the west part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue gently curving to the east and "
   "south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"grove","fig tree","fig trees"}),"Just to "
   "your southeast is a small grove of big leaved fig "
   "trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"fig","figs"}),"You can't see them from here.\n");

   AddDetail( ({"hedge","tiny hedge"}), "These are elven leaf hedges. "
   "They are meticulously coiffed. It is rumored, elven leaf hedges "
   "are the perferred homes of hedgehogs.\n");

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
       "Dim light from the palace reaches this are corner of the "
       "road throwing the trees into deep shadow.\n"]));


   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -50,-20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");


   AddExit("south", SIL_CENTER("outside31"));
   AddExit("southeast", SIL_CENTER("garden1"));
   AddExit("east",  SIL_CENTER("outside29"));
}
