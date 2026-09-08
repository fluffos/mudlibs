// This is a small road, that leads toward the temple to the northeast
// created:       Sonic    [29-May-1997]
// last changed:  Chara    [31-May-1997] - description
//                Tune     [01-Jun-1997] - details, kleinkram
//                Chara    [02-Jun-1997] - details
//                Chara    [03-Jun-1997] - ever more details ;)
//                Sonic    [01-Jul-1997] - added region/coordinates
//                Tune     [08-Oct-1997] - 2 more details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>

inherit SILBASEROOM;

int pray_here()
{
   if(({int})TP->QueryGhost())
   {
      write(
       "You pray to Xalandre. A shimmering form appears before you and you "
       "feel strangely altered, as the friendly presence leaves again.\n");
      show(
        CAP(NAME(TP))+" wholeheartedly praises Xalandre and is blessed. A "
       "shimmering form appears before "+HIMHER(TP)+" and "+HESHE(TP)+
       " appears in solid form.\n");
      TP->SetGhost(0);
   }
   else
   {
      write("You kneel down and offer a prayer to Xalandre.\n");
      say(CAP(NAME(TP))+" kneels down and praises Xalandre.\n");
   }
   return 1;
}

int leave_temple(string str)
{
   notify_fail("Leave what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"temple")!=-1)
   {
      write("You leave the temple of Xalandre.\n");
      TP->move(SIL_WEST("templeroad3"),M_GO,"west");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);

   Set(P_INT_SHORT,"The temple of Xalandre");
   Set(P_INT_LONG,
    "This is the temple of Xalandre, Mistress of the Waves, to whom the "
    "fishermen of Silvere pray for good bounty and a safe return.  The "
    "building is of simple design, made from glistening white stucco, and "
    "the scent of the sea wafts in through open windows.  A statue of the "
    "goddess adorns a small alcove to the north, and the altar is to the "
    "east.\n" );

   Set(P_INT_WIZMSG," WEST (or LEAVE): leave the temple.\n"
    "\n"
    "How about a legend to go with Xalandre? Like her sweetheart was "
    "lost at sea, and now she mourns eternally for him? etc.etc.\n");

   Set(P_INT_SMELL,
    "The scent of pungent, briney seasalt hangs in the breeze.\n");

   Set(P_INT_NOISE,
    "The soft whoosh, whoosh of the tide can be heard through the "
    "open windows.\n");

   AddDetail("altar",
    "The altar is simple yet beautiful.  Made of mother-of-pearl, "
    "it catches and reflects the sunlight from the windows beautifully. "
    "On the front of the altar is a dolphin made from coral. "
    "If you are dead, and wish to take on a living form again, "
    "you can pray here at the altar of Xalandre and hope that she "
    "takes pity on your mortal soul.\n");

   AddDetail("glistening white stucco",
    "A simple but common building material in this part of the world.\n");

   AddDetail("building", #'QueryIntLong /*'*/); //couldn't think of anything better

   AddDetail("sunlight",
    "The sunlight streams in through the open windows and bathes the "
    "temple in a warm glow.\n");

   AddDetail("windows",
    "The large windows are open to let the light and the sea breeze pour "
    "in.\n");

   AddDetail( ({"dolphin", "dolphins"}),
    "Do you mean the 'dolphin on altar' or the 'dolphin on statue'?\n");

   AddDetail("dolphin on altar",
    "The statue of the dolphin is made out of beautiful pink coral, and "
    "has a large pearl for its eye.\n");

   AddDetail("coral",
    "The dolphin is made of small pieces of pink and orange coral, pieced "
    "together in a mosaic style.\n");

   AddDetail("pearl",
    "The eye of the dolphin is a large, lovely pearl.\n");

   AddDetail( ({"dolphin on statue", "dolphins on statue"}),
    "The two dolphins flank the statue of Xalandre.  You are uncertain "
    "if they are playmates or guardians.\n");

   AddDetail( ({"statue", "xalandre", "goddess", "young woman"}),
    "The statue of Xalandre depicts a lovely but sorrowful young woman, "
    "her long hair strewn with seaweed, and two dolphins attend her. "
    "The statue is bedecked with flowers by families of fishermen asking "
    "for their safe return, and children tend to place beautiful shells "
    "they find on the beach at her feet.\n");

   AddDetail ( ({"flower", "flowers"}),
    "Garlands of flowers are draped over the statue of Xalandre.  It is "
    "customary for the families of sailors to offer flowers to the "
    "goddess to ensure the safe return of their loved ones.\n");

   AddDetail( ({"garland", "garlands"}),
    "The garlands are comprised of all different kinds of flowers, from "
    "wildflowers that grow in the fields to expensive hothouse roses and "
    "orchids.\n");

   AddDetail( ({"hair", "seaweed"}),
    "On closer inspection, it is difficult to see if the seaweed is "
    "caught in her hair, or if it is growing there.\n");

   AddDetail("alcove",
    "This is a small recess where the statue of Xalandre resides.\n");

   AddDetail( ({"shells","many shells"}),
    "The best shells that wash up on the shore are left here.  Colorful "
    "bits of coral, delicate and colorful abalone, dried starfish, "
    "and even a large conch shell.\n");

   AddVItem( ([
              P_IDS:   ({"conch", "shell"}),
              P_LONG:  "It is said that if you listen to the shell of the "
                       "conch, you can hear Xalandre's voice inside.\n",
              P_NOISE: "Listening to the shell, you hear the gentle "
                       "sounds of waves washing against the shore. "
                       "The fishermen believe that this is the voice "
                       "of the goddess, calling for her lost love.\n"
              ]) );

   AddRoomCmd( ({"pray","regenerate"}),#'pray_here /*'*/);
   AddRoomCmd( "leave", #'leave_temple /*'*/);

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -150,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
    "It is not possible to walk in that direction.\n");

   AddExit("west",   SIL_WEST("templeroad3"));
   AddExit("north",  SIL_WEST("xal_chapel"));
}
