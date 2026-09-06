// The palace place before the walls of the east wing
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates
// Changed:       Joan     [04-Sept-2001] Added stuff


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <config.h>
#include <macros.h>
#include <nightday.h>

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
   Set(P_INT_SHORT,"The place before the palace");
   Set(P_INT_LONG,
"The walls of the main building are right before you. Latticed windows "
"can be seen all over the basement of the building. To the west is the "
"enrance of the palace. The mainroad to the south starts there also. "
"All over the place are beds with artfully arranged flowers and beautiful cascades of roses.\n");

   Set(P_INT_WIZMSG,
" West:  To the entrance of the palace.\n"
" South: The place and the surrounding road.\n");

   AddVItem(
    ([ P_IDS : ({ "lantern", "light", "lanterns", "lights" }),
       P_ADS : ({ "cast", "iron", "alabaster" }),
       P_LONG :
        "Cast iron frames hold thin, rectangular sheets of alabaster "
        "as side panels, which glow with a soft white light when the "
        "lanterns are lit.\n"
    ]) );

   AddDetail( ({"palace","palace wall","front palace wall"}),
   "The front palace wall stretches into the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"bench","marble bench","white","white marble bench"}),
   "A wide low beautifully crafted white marble bench sits among the "
   "dazzling displays of flowers.\n");


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

  AddDetail( ({"flower","flowers","saliums","salium", }),
   "A myriad of soft pink saliums border the "
   "shrub rose and palace wall.\n");


   SetIntSmell("The flowers fill the air with their delicate "
   "perfume.\n");

   Set(P_TIME_MSG,
    ([ NIGHT_DEFAULT_MSG:
       "Cast iron lanterns with alabaster sides glow softly, casting a soft "
       "glow onto the paths through the foliage. The fountain in the center "
       "of the square is also illuminated by the soft glow of alabaster "
       "lamps.",
       DAY_DEFAULT_MSG:
       "Cast iron lanterns with alabaster panels line the edges of the "
       "paths."
    ]) );

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 10,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("south", SIL_CENTER("palplace3"));
   AddExit("west",  SIL_CENTER("palplace5"));
}

#if 0
void notify_leave(mixed a, int b, mixed c)
{
  RemoveSitter( previous_object() );
  ::notify_leave(a,b,c);
}

Code in bench nonfunctional
varargs string Content(string what, mixed excl, object pl)
{
  return bench::Content(what, excl, pl);
}
#endif
