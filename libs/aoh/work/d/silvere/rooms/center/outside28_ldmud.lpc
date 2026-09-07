// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [29-Jun-1997] added region/coordinates
//last changed:   Joan     [11-Oct-1997] added some details
//last changed:   Joan     [16-Oct-1997] added random sounds for time
//last changed:   Joan     [27-Nov-1997] added south exit

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
   Set(P_INT_SHORT,"Avenue at the palace");
   Set(P_INT_LONG,
"The wide tree lined avenue gracefully continues to the east "
"and to the west. From here you see the brownstones of the "
"rear palace wall. To the south, tiny hedges border, a small "
"neat grove of fig trees grows between the main building and "
"the west wing. "
"@@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" East: to the east and north part of Silvere and other places.\n"
" West: the road around the palace, to the west part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue continues to the east and "
   "west.\n");

   AddDetail( ({"hedge","tiny hedge"}), "These are elven leaf hedges. "
   "They are meticulously coiffed. It is rumored, elven leaf hedges "
   "are the perferred homes of hedgehogs.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The stones brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the trees.\n");

   AddDetail( ({"grove","fig tree","fig trees"}),"Just to "
   "your south is a small grove of big leaved fig trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"fig","figs"}),"You can't see them from here.\n");

   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "The rear palace wall stretches into the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food through the soft "
   "grass beneath lime trees..\n");

   SetIntSmell("You are delighted with the clean fresh scent "
   "of ripening limes.\n");

   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Seagulls glide silently high over head. Mourning doves "
       "coo as they forage through the soft grass under the trees.\n",
     NIGHT_DEFAULT_MSG:
       "Light from the palace illuminates the avenue and trees. "
       "The trees almost come alive in the gentle breeze "
       "painting the ground with long slow dancing "
       "shadows.\n"]));

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -30,-20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");


   AddExit("west", SIL_CENTER("outside29"));
   AddExit("south", SIL_CENTER("garden2"));
   AddExit("east", SIL_CENTER("outside27"));
}
