// Room layout. The road here opens to a large place with the
// palace in the center.
// created:       Sonic    [01-Jun-1997]
// changed:       Sonic    [15-Jun-1997]
//                Sonic    [01-Jul-1997] Region/Coordinates added
// changed:       Joan     [05-Sept-2001] Added all kinds of stuff



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
   "A distant shout from the city reaches your ears.\n",
   "The clickety clack coach of wheels intrude into palace solitude.\n",
   "The loud voices of men arguing unpleasantly reach your ears.\n",
   "Somewhere a baby is crying.\n",
   "You hear cats fighting somewhere near.\n",
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
   Set(P_INT_SHORT,"Central place, west end");
   Set(P_INT_LONG,
"To the east palace plaza opens before you. The brownstone palace walls begin to rise in the distance. "
"To the west the avenue stretches into Silvere and the harbour areas of Silvere. Lime "
"trees stand sentry to the north and south sides of the avenue. "
"@@TimeMsg@@\n");

AddDetail( ({"road","avenue","path"}),"The western approach "
   "intersects to graceful north and south avenue of the palace."
   "A huge white marble statue quietly gaurds the west wall of "
   "the palace. The avenue stretches east toward the palace "
   "and west into the city.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The stones brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");

   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "You can see the west palace wall in the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"statue"}),"You gaze east towards the statue "
   "but you can't get a good look at it from here.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food beneath the shrubs.\n");

   SetIntSmell("The smell of ripening limes fill the air.\n");

   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Seagulls glide high overhead and "
       "mourning doves coo as they forage for food beneath "
       "the lime trees.\n",
     NIGHT_DEFAULT_MSG:
       "City lights twinkle and beckon to you from the distance. "
       "Dim light from the palace plays across the avenue and "
       "trees. Long sharp shadows cut across the stone road.\n"]));


   Set(P_INT_WIZMSG,
" West: to the western part of the city and the harbour.\n"
" East: To the palace at the central place.\n");



   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -70,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west",   SIL_WEST("westroad11"));
   AddExit("east",   SIL_CENTER("outside1"));
}
