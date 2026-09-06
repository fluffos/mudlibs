// The mainroad to the south gates
// created:       Sonic    [15-Jun-1997]
// changed:       Sonic    [01-Jul-1997]  added region/coordinates
// Changed:       Joan     [01-Sept-2001] added all kinds of stuff



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

int is_boots;

string cl_statue_long()
{

	string longdes;

longdes="It is almost as if a fierce winged human male is "
        "frozen in white marble. ";

if (is_boots)



  longdes+="He wears a pair of elegant black boots. ";
else
  longdes+="He wears a pair of elegant black boots. Star fish "
           "and eels swirl busily about his feet. ";

longdes+="Eels and star fish, frozen in the marble, swirl about "
         "his feet. He wears a swirling whirlpool frozen "
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

  if(({int})NIGHTDAY->IsDay())
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
"The tree lined palace avenue stretches from east to west and to the north and south. The "
"stones of the front of the palace can be seen from here. A broad "
"road leads north to palace entrance and south to the harbour. A huge white marble statue "
"guards the northern approach to the palace. Pink and white shrub roses "
"line the base of the statue. @@TimeMsg@@\n");


   Set(P_INT_WIZMSG,
" North: A small place with the entrance into the palace.\n"
" West:  To the western part, the harbour and some other places.\n"
" East:  To the south and east part of the town.\n"
" South: To the south is the main road to town.\n");



   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -10,40,0 }), C_SILVERE }) );

   AddDetail( ({"road","avenue","path"}),"The graceful avenue "
   "intersects to the northern approach to the palace. A huge "
   "white marble statue quietly gaurds the northern approach to "
   "the palace. The avenue stretches elegantly to east and "
   " west and north and south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");


   AddDetail( ({"palace","palace wall","front palace wall"}),
   "The rear palace wall stretches into the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food beneath the shrubs.\n");

   AddDetail( ({"rose","roses","shrubs"}),"Thick shrub "
   "roses line the base of the huge statue. Their profuse "
   "blooms of soft pink and creamy white roses tumble from "
   "mid base to the emerald grass below in a breathtaking "
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
       P_READ_MSG : "The Gaurdian Sarykan. He is the guardian of the "
       "element known as water.\n" ,
       P_NOISE : "A cold wind touches your ear. You hear a hoarse "
       "whisper: The water is alive. It is never still and never "
       "silent.\n"
        ])
      );

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ 0,-20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. You must have knocked "
"yourself dizzy, because you heard the statue laugh at you.\n");

   AddExit("south", SIL_SOUTH("mainroad1"));
   AddExit("north", SIL_CENTER("palplace2"));
   AddExit("east",  SIL_CENTER("outside10"));
   AddExit("west",  SIL_CENTER("outside9"));
  is_boots = 1;
   AddRoomCmd("touch", "cmd_touch");
}



void reset()
{
  ::reset();
}

int cmd_touch(string str)
{
  string *arr;
  object boots;

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
             NAME(TP)+" touches the statue of Sarykan.\n",
             "Someone touches the statue of Sarykan.\n"
            }), TP );

  if(!is_boots)
    {
    write("You touch the statue of Sarykan, but nothing happens. "
          "Maybe try again later.\n");
    return 1;
    }

  write("You touch the statue and a a pair of boots falls down\n");

  boots = clone_object("/d/silvere/obj/armour/sarykan");
  boots->move(ENV(TP), M_SILENT);


  is_boots = 0;

  return 1;
}



