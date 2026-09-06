// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordnates
// last changed:  Joan     [15-Oct-1997]  added some details
// last changed:  Joan     [31-Oct-1997]  added statue
// last changed:  Mistral and Joan [16-Nov-1007] added sword to statue.

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

int is_sword;

string cl_statue_long()
{
string longdes;

longdes="It is almost as if a fierce winged human male is "
        "frozen in white marble. ";

if (is_sword)
  longdes+="In either hand he wields huge ice swords. ";
else
  longdes+="He wields a huge ice sword in one hand. It looks like there "
           "is one missing in the other hand. ";

longdes+="Tiny wind devils, frozen in the marble, play about "
         "his feet and shoulders. He wears a snowy whirlwind frozen "
         "in marble for a cloak. You see dirty fingerprints on the "
         "statue. There is something carved into the base of "
         "the beautiful white marble. Perhaps you should read it.\n";

return longdes;
}

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
   "Did the statue whisper something to you?\n"
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
   Set(P_INT_SHORT,"Avenue of the Palace");
   Set(P_INT_LONG,
"The tree lined palace avenue stretches from east to west. The "
"brownstones of the rear palace can be seen from here. A broad "
"road leads north to the city. A huge white marble statue "
"guards the rear palace wall. Pink and white shrub roses "
"line the base of the wall. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" North: to the northern district.\n"
" East:  to the east part of Silvere and other places.\n"
" West:  the road around the palace, to the west part.\n");

   AddDetail( ({"road","avenue","path"}),"The graceful avenue "
   "intersects to the northern approach to the palace. A huge "
   "white marble statue quietly gaurds the rear north wall of "
   "the palace. The avenue stretches elegantly to east and "
   " west.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The stones brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");


   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "The rear palace wall stretches into the distance. The "
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
       "forage for food beneath the shrubs and around "
       "the base the of the beautiful statue.\n",
     NIGHT_DEFAULT_MSG:
       "To the north city lights twinkle in the distance. "
       "Bright lights from the palace light the avenue "
       "and trees. While the trees cast long dancing shadows upon "
       "the stone road, the elegant white statue glows softly "
       "in the night light.\n"]));

     AddVItem(
       ([ P_IDS : ({ "statue"}) ,
       P_ADS : ({ "white", "marble" }) ,
       P_LONG :  #'cl_statue_long /*'*/,
       P_READ_MSG : "The Gaurdian Kyrie. He is the guardian of the "
       "element known as wind.\n" ,
       P_NOISE : "A cold wind touches your ear. You hear a hoarse "
       "whisper: The wind is forever. It is never still and never "
       "silent.\n"
        ])
      );

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,-20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. You must have knocked "
"yourself dizzy, because you heard the statue laugh at you.\n");

   AddExit("north",SIL_CENTER("northroad"));
   AddExit("east", SIL_CENTER("outside24"));
   AddExit("west", SIL_CENTER("outside26"));

  is_sword = 1;

   AddRoomCmd("touch", "cmd_touch");


}

void reset()
{
  ::reset();
}

int cmd_touch(string str)
{
  string *arr;
  object sword;

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
             NAME(TP)+" touches the statue of Kyrie.\n",
             "Someone touches the statue of Kyrie.\n"
            }), TP );

  if(!is_sword)
    {
    write("You touch the statue of Kyrie, but nothing happens. "
          "Maybe try again later.\n");
    return 1;
    }

  write("You touch the statue and a sword falls down\n");

  sword = clone_object("/d/silvere/obj/weapons/kyrei");
  sword->move(ENV(TP), M_SILENT);


  is_sword = 0;

  return 1;
}

