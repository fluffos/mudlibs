// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [29-Jun-1997] Coordinates added
// last changed:  Sonic    [01-Jul-1997] Regions added
// last changed:  Joan     [18-Oct-1997] added some details and sound
// last changed:  Joan     [31-Oct-1997] added statue
// last changed:  Mistral and Joan [17-Nov-1007] added cloak to statue.

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

int is_cloak;

string cl_statue_long()
{
string longdes;

longdes="The graceful sculpture is of a fierce winged human "
        "female. ";

if (is_cloak)
  longdes+="Her cloak is a cold marble firery maelstrom. ";
else
  longdes+="Tali's fire cloak is missing. ";

longdes+="She wields a large firery sword in either hand. Marble "
         "fire imps dance upon her shoulder. You see dirty "
         "fingerprints on the statue. There is something carved "
         "into the base of the beautiful white marble. Perhaps "
         "you should read it.\n";

return longdes;
}

string QueryIntNoise()
{
  string *tmp;

  tmp = ({
   "The noise of the city rudely intrudes upon the peace "
   "of the quiet avenue.\n",
   "You hear a distant shout from the east.\n",
   "The clickety clack coach of wheels intrude into palace solitude.\n",
   "You hear a horse clip clop along in the distance.\n",
   "A chapel bell rings in the distance.\n",
   "Did the statue whisper something to you?\n",
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
   string statue_id;
   string statue_text;

   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Avenue of the Palace");

   Set(P_INT_LONG,
"Here the graceful palace avenue meets a broad avenue "
"wandering into eastern Silvere. Lime trees line the avenue "
"to the north and south while an elegant marble statue "
"guards the east side of the palace. Red shrub roses border "
"the brown stone palace wall and statue base. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" East:  The road leads to the east part of Silvere.\n"
" South: To the west and southpart of Silvere, the palace, etc.\n"
" North: to the northern part of Silvere.\n");

   AddDetail( ({"road","avenue","path"}),"Elegant lime trees border "
   "the smooth brownstone avenue gently continues north and "
   "south.\n");

   AddDetail( ({"roses","rose","rose bush","shrubs"}),"Gorgeous "
   "red shrub roses cascade from almost as high as the center of "
   "the brownstone palace wall to the emerald green carpet of "
   "grass. They are dazzling.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The smooth brownstones are carefully cut and laid with "
   "almost seamless precision.\n");

   AddDetail( ({"tree","lime trees","lime tree","trees"}),
   "A row of well tended lime trees border the avenue. Clusters "
   "of ripening limes crowd the branches of the mature trees.\n");

   AddDetail( ({"limes","lime"}),"The limes are not ripe yet.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"jays","mocking birds","jay","mocking bird",}),
   "Noisy jays and mocking birds chase each other through "
   "the trees.\n");

   SetIntSmell("The heady perfume of the roses fills the air.\n");


   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "A distant glimpse of the hustle and bustle of the "
       "city to east intrudes upon the tranquility of the "
       "palace.\n",
     NIGHT_DEFAULT_MSG:
       "Distant city lights twinkle to east while bright "
       "lights from the palace spill upon the road. Shadows "
       "fall away from the white marble statue as it softly glows "
       "in the lights of the night.\n"]));

   statue_text = "The Gaurdian Tali. She is the guardian of the "
                 "element known as fire. \n";

   statue_id =
   AddVItem(
     ([ P_IDS : ({ "statue"}) ,
        P_ADS : ({ "white", "marble" }) ,
        P_LONG :  #'cl_statue_long /*'*/,
        P_PREPS :  ({ "on", "of" }),
        P_READ_MSG :  statue_text,
        P_NOISE : "A hot wind blows near your ear. You hear a whisper: "
                  "Step into the fire and let it cleanse you.\n"
      ])
     );

   AddVItem(
     ([ P_IDS : ({ "inscription", "writing", "words" }),
        P_LONG :  statue_text,
        P_READ_MSG : statue_text,
     ]), statue_id );

   AddVItem(
     ([ P_IDS : ({ "base" }),
        P_LONG :
          "The base of the fine statue was hewn from the same pristine "
          "translucent marble as the statue. Something is inscribed on "
          "the base in flowing script.\n",
        P_READ_MSG : statue_text,
     ]), statue_id );

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 50,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. You are dizzy and "
"you are sure the statue laughed at you.\n");

   AddExit("east",  SIL_CENTER("eastroad1"));
   AddExit("south", SIL_CENTER("outside16"));
   AddExit("north", SIL_CENTER("outside18"));

  is_cloak = 1;

   AddRoomCmd("touch", "cmd_touch");
}



void reset()
{
  ::reset();
}


int cmd_touch(string str)
{
  string *arr;
  object cloak;

  if(!str)
  {
    notify_fail("Touch the statue!\n", NOTIFY_ILL_ARG);
    return 0;
  }


  arr = norm_id(str, 1);

 if(-1 == member(({"statue","marble statue"}), arr[sizeof(arr)-1] ) )
  {
    notify_fail("Well, you can try ... \n", NOTIFY_NOT_VALID);
    return 0;
  }

  msg_room( ENV(TP), CMSG_ROOM|MMSG_SEE,
            ({
             NAME(TP)+" touches the statue of Tali.\n",
             "Someone touches the statue of Tali.\n"
            }), TP );

  if(!is_cloak)
    {
    write("You touch the statue of Tali, but nothing happens. "
          "Maybe try again later.\n");
    return 1;
    }

  write("You touch the statue and a cloak falls down\n");

 cloak = clone_object("/d/silvere/obj/armour/tali");
  cloak->move(ENV(TP), M_SILENT);


  is_cloak = 0;

  return 1;
}


