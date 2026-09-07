// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [29-Jun-1997]  added region/coordinates
//                Joan     [16-Oct-1997]  added some details

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
   Set(P_INT_SHORT,"Avenue of the Palace");
   Set(P_INT_LONG,
"To the east the avenue becomes broader where it crosses a "
"wide road heading north. Sage and mint beds along with "
"orange star liliums line the base of the palace wall, "
"while graceful lime trees border the opposite side of "
"the avenue. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" West: to the West and north part of Silvere and other places.\n"
" East: the road around the palace, to the east part.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue continues to the east and "
   "west.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The stones brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "The rear palace wall stretches into the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food through the soft "
   "grass beneath lime trees.\n");

   AddDetail("sage","The grey-green leaves and "
   "small purple flowers of the sage, softly compliment the "
   "bright star liliums and dark green mint.\n");

   AddDetail("mint","Tall deep green mint plants line the "
   "base of the rear palace wall. They frame the wall for the "
   "showy orange star liliums and small lovely shrubs of sage.\n");

   AddDetail("star liliums","Large bright orange star liliums "
   "sit in neat rows against the green backdrop of the "
   "taller mint. The gay orange flowers softly compliment "
   "the grey-green of the sage, deep green mint and "
   "the brown hues of the stone palace walls.\n");

   SetIntSmell("Sage and mint combine with the clean "
   "fresh scent of ripening limes wafting through the "
   "air.\n");


   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "Seagulls glide silently high over head. Mourning "
       "doves coo as they forage though the soft grass under "
       "the trees and through the flower beds.\n",
     NIGHT_DEFAULT_MSG:
       "Bright lights from the palace light the avenue "
       "and trees. The trees cast long dancing shadows upon "
       "the stone road.\n"]));

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 10,-20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("west", SIL_CENTER("outside25"));
   AddExit("east", SIL_CENTER("outside23"));
}
