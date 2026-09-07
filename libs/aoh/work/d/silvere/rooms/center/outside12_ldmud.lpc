// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [29-Jun-1997] Coordinates added
//                Sonic    [01-Jul-1997] Region added
// changed:       Joan     [03-Sept-2001] Added all kinds of stuff


#include <nightday.h>
#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <msgclass.h>
#include <macros.h>

inherit SILBASEROOM;

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
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Road at the palace");
   Set(P_INT_LONG,
"The tree lined palace avenue stretches from east to west and to the north. The "
"stones of the front of the palace can be seen from here.  Pink and white shrub roses "
"line the base of the wall. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" West: To the west and southpart of Silvere, the palace, etc.\n"
" East: to the east part.\n");

AddDetail( ({"road","avenue","path"}),"To the west the graceful avenue "
   "intersects to the northern approach to the palace. "
   "The avenue stretches elegantly to east and "
   " west.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The stones brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");


   AddDetail( ({"palace","palace wall","front palace wall"}),
   "The front palace wall stretches into the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food beneath the shrubs.\n");

   AddDetail( ({"rose","roses","shrubs"}),"Thick shrub "
   "roses line the base of the palace wall. Their profuse "
   "blooms of soft pink and creamy white roses tumble from "
   "mid wall to the emerald grass below in a breathtaking "
   "display of natural beauty.\n");


   SetIntSmell("The roses fill the air with their delicate "
   "perfume.\n");

   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "You glimpse the hustle and bustle of the city "
       "through the city gates. Seagulls glide high "
       "overhead and mourning doves coo as they "
       "forage for food beneath the shrubs. \n",
     NIGHT_DEFAULT_MSG:
       "To the south city lights twinkle in the distance. "
       "Bright lights from the palace light the avenue "
       "and trees. While the trees cast long dancing shadows upon "
       "the stone road. "
       "in the night light.\n"]));

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 30,40,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("east",  SIL_CENTER("outside13"));
   AddExit("west",  SIL_CENTER("outside11"));
}
