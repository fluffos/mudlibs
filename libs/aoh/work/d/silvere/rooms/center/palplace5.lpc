// The palace entrance to the north. The mainroad starts here
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates
// changed:       Joan     [04-Sept-2001] Added stuff
// its the new one


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <config.h>
#include <macros.h>
#include <nightday.h>
#include <messages.h>
#include <msgclass.h>
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


int enter_palace()
{
    msg_write(CMSG_GENERIC,
       "You walk past the guards into the palace. "
       "They eye you suspicious, but do nothing.\n");
    TP->move(SIL_PALACE("palenter"),M_GO);
    return 1;
}


int enter_palace2(string str)
{
    notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
    if(!str) return 0;
    if(!TP)  return 0;
    if(strstr(lower_case(str),"palace")!=-1 ||
       strstr(lower_case(str),"building")!=-1)
    {
       enter_palace();
       return 1;
    }
}

varargs void create()
{
    ::create();
    Set(P_INDOORS,0);
    Set(P_INT_SHORT,"At the entrance into the palace");
    Set(P_INT_LONG,
"To the north the elegant entrance to the palace opens up before you. "
"The brownstones of the deep entry way are covered with hieroglyphics. "
"A broad road leads from here "
"between the flowerbeds and roses to the south toward the citygates "
"of Silvere. @@TimeMsg@@\n");


    Set(P_INT_WIZMSG,
" North: (or Enter) Enter the palace.\n"
" South: The mainroad toward the southern gates of Silvere.\n"
" West:  To the walls of the west wing of the palace.\n"
" East:  To the walls of the east wing of the palace.\n");


AddDetail(  ({"hieroglyphics","hieroglyphic"}),
"The intricate carvings tell the story of the founding of "
"Silvere. \n");



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
    Set(P_COORDINATES, ({ ({ 0,20,0 }), C_SILVERE }) );
    Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling, that\
  everyone laughs at you.\n");
      AddRoomCmd("enter",#'enter_palace2 /*'*/);
    AddExit("south", SIL_CENTER("palplace2"));
    AddExit("north", #'enter_palace /*'*/);
    AddExit("east",  SIL_CENTER("palplace6"));
    AddExit("west",  SIL_CENTER("palplace4"));
}