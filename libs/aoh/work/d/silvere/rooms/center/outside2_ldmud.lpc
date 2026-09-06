// Room layout. The road here leads around the palace
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  added regions/coordinates
// last changed:  Joan     [01-Nov-1997]  added some details
// last changed:  Mistral and Joan [17-Nov-1007] added helmet to statue.

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

int is_helmet;

string cl_statue_long()
{
string longdes;

longdes= "Delicately sculpted in fine white marble is a "
         "beautiful winged female human. ";

if (is_helmet)
  longdes+="She wears an intricately carved marble helmet upon "
           "her head. ";
else
  longdes+="Rilana's helmet is missing. ";

longdes+="Her feet rest upon cold marble mountains. White "
         "marble wood nymphs dance upon her shoulders. You see dirty "
         "finger prints on the statue. There is something carved into "
         "the base of the beautiful white marble. Perhaps you should "
         "read it.\n";

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
  string statue_id;

   if(::create()) return 0;
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Avenue of the Palace");
   Set(P_INT_LONG,
"The tree lined palace avenue stretches from north to south. "
"A broad road leads west into the city. A huge white marble statue "
"guards the west palace wall. Yellow shrub roses line the base "
"of the wall. @@TimeMsg@@\n");

   Set(P_INT_WIZMSG,
" West:  to the western part of the city and the harbour.\n"
" North: Follow the road to the north around the palace.\n"
" South: Follow the road to the entrance of the palace.\n");

   AddDetail( ({"road","avenue","path"}),"The graceful avenue "
   "intersects to the western approach to the palace. A huge "
   "white marble statue quietly gaurds the west wall of "
   "the palace. The avenue stretches elegantly to north and "
   " south.\n");

   AddDetail( ({"stone","stones","brownstones","brownstone"}),
   "The stones brownstones are carefully cut and laid with "
   "almost seamless precision. The avenue is paved with the "
   "same brownstones used to construct the magnificent "
   "palace.\n");


   AddDetail( ({"palace","palace wall","rear palace wall"}),
   "The west palace wall stretches into the distance. The "
   "palace is constructed of the same brown stone that paves "
   "the elegant avenue.\n");

   AddDetail( ({"gull","seagull","seagulls","gulls"}),"Big "
   "grey and white gulls glide lazily along searching for "
   "an easy meal.\n");

   AddDetail( ({"dove","mourning dove","mourning doves","doves"}),
   "Small dappled grey doves forage for food beneath the shrubs.\n");

   AddDetail( ({"rose","roses","shrubs"}),"Thick shrub "
   "roses line the base of the palace wall. Myrads "
   "of blooms fall from mid wall to the emerald grass "
   "forming a fragrant yellow blanket of perfect yellow roses.\n");


   SetIntSmell("The roses fill the air with their delicate "
   "perfume.\n");

   Set(P_TIME_MSG,
    ([
     DAY_DEFAULT_MSG:
       "You glimpse the hustle and bustle of the city "
       "through the western city gates. Seagulls glide high "
       "overhead and mourning doves coo as they "
       "forage for food beneath the shrubs and around "
       "the base the of the beautiful statue.\n",
     NIGHT_DEFAULT_MSG:
       "To the west city lights twinkle in the distance. "
       "Bright lights from the palace light the avenue "
       "and trees. While the trees cast long dancing shadows upon "
       "the stone road, the elegant white statue glows softly "
       "in the night light.\n"]));

      statue_id = AddVItem(
       ([ P_IDS : ({ "statue"}) ,
       P_ADS : ({ "white", "marble" }) ,
       P_LONG :  #'cl_statue_long /*'*/,
       P_READ_MSG : "The Gaurdian Rilana. She is the guardian of the "
       "element known as earth.\n" ,
       P_PREPS : ({ "on", "of" }),
       P_NOISE : "A soft wind caresses your ear. You hear a faint "
       "whisper: Be gentle upon earth, mortal, for you only get one.\n"
             ])
        );

      AddVItem(
        ([ P_IDS : ({ "inscription" }),
           P_READ_MSG :
            "The Gaurdian Rilana. She is the guardian of the "
            "element known as earth.\n",
           P_LONG :
            "The Gaurdian Rilana. She is the guardian of the "
            "element known as earth.\n"
         ]), statue_id );

       AddVItem(
        ([ P_IDS : ({ "base" }),
           P_READ_MSG :
            "The Gaurdian Rilana. She is the guardian of the "
            "element known as earth.\n",
           P_LONG :
            "The base of the statue was hewn from the same fine "
            "white marble as the statue itself. There is an "
            "inscription engraved on the base.\n"
         ]), statue_id );

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -50,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into a tree like an idiot. You must have knocked "
"yourself dizzy, because you heard the statue laugh at you.\n");

   AddExit("west",   SIL_CENTER("outside1"));
   AddExit("south",  SIL_CENTER("outside3"));
   AddExit("north",  SIL_CENTER("outside32"));


  is_helmet = 1;

   AddRoomCmd("touch", "cmd_touch");


}

void reset()
{
  ::reset();
}


int cmd_touch(string str)
{
  string *arr;
  object helmet;

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
             NAME(TP)+" touches the statue of Rilana.\n",
             "Someone touches the statue of Rilana.\n"
            }), TP );

  if(!is_helmet)
    {
    write("You touch the statue of Rilana, but nothing happens. "
          "Maybe try again later.\n");
    return 1;
    }

  write("You touch the statue and a helmet falls down\n");

  helmet = clone_object("/d/silvere/obj/armour/rilana");
  helmet->move(ENV(TP), M_SILENT);


  is_helmet = 0;

  return 1;
}

