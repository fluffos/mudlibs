// The western tower of the palace, top of tower beyond guards HQ
// created:       Taurec   [11-May-1998]
// last changed:

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
inherit BASEROOM;

mixed look_mountains()
{
  if(({int})NIGHTDAY->IsDay()) return
    "The snowcapped mountains block the sight further east. "
    "Somewhere there, there must be the dark city Sykorath.\n";
  else return 0;
}

mixed look_houses(){
  if(({int})NIGHTDAY->IsDay()) return
   "This is Silvere, the capital of light. From here it looks like "
   "an accumulation of hundreds of little roofs snuggling up to each "
   "other, trails of smoke coming out of their chimneys. It's a "
   "cozy town.\n";
  else return
   "You can only see the illuminated windows of the houses down "
   "there.\n";
}

mixed look_ocean(){
  if(({int})NIGHTDAY->IsDay()) return
   "That's the Sea of Shamyra, travelled by lots of ships.\n";
  else return
   "Scattered all over the dark water, you can see the position "
   "lamps of several lonely ships out there.\n";
}

mixed look_spots(){
  if(({int})NIGHTDAY->IsDay()) return 0;
  else return
   "These spots of light down there come from candles, torches and "
   "feature fireplaces lit in the cozy houses of Silvere.\n";
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"The top of the western tower");
   Set(P_INT_NOISE,"You listen to some wind, and from the west "
    "you hear the faint roar of the sea of Shamyra.\n");
   Set(P_INT_LONG,
    "You are ontop of the western tower of Lu'Meyn's palace. "
    "Pinnacles crown it all around, and the view here is "
    "breathtaking. @@TimeMsg@@\n");
   Set(P_TIME_MSG,
       ([DAY_DEFAULT_MSG:
         "Most beautiful to watch is the Sea of Shamyra that extends "
         "westwards until it dissappears in haze near the horizon. "
         "A little bit nearer, you can see the surrounding city with "
         "its hundreds of nice houses crouched tightly together. "
         "You can also see the mountains far off... somewhere there "
         "is Sykorath, the dark city. ",
	 NIGHT_DEFAULT_MSG:
         "Beyond you little being, the firmament spreads over you like black "
         "velvet pierced by thousands of thousands of stars, whereas "
         "the city below seems to be the reflection of the sky, "
         "with hundreds of small cosy looking spots of light flowing "
         "out of the windows."
   ]));
   Set(P_INT_WIZMSG,
    " Down : back to the royal guards HQ of the palace.\n");

   AddDetail(({"staircase","stairs","flight"}),"The staircase leads "
     "downwards in a tight spiral.\n");

   AddDetail(({"pinnacle","pinnacles"}),"In sooner times, these "
    "pinnacles were made for purposes of defense. But nowadays "
    "they are quite useless.\n");

   AddVItem(([
     P_IDS: ({"sea","ocean","shamyra"}),
     P_ADS: ({"infinite","blue"}),
     P_LONG: #'look_ocean /*'*/
   ]));
   AddVItem(([
     P_IDS: ({"mountains","mountain"}),
     P_ADS: ({"huge","snowcapped"}),
     P_LONG: #'look_mountains /*'*/
   ]));
   AddVItem(([
     P_IDS: ({"town","city","silvere","village","house","houses"}),
     P_ADS: ({"cozy"}),
     P_LONG: #'look_houses /*'*/
   ]));
   AddVItem(([
     P_IDS: ({"spot","spots","windows","window","light"}),
     P_ADS: ({"tiny","cozy"}),
     P_LONG: #'look_spots /*'*/
   ]));

   AddItem(NPC("royal_guard"),REFRESH_REMOVE,1);

   Set(P_INT_MAP,"palace");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -30,20,20 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
    "You walk into the wall like an idiot. Somehow you have the "
    "feeling, that everyone laughs at you.\n");
   AddExit("down", SIL_PALACE("palwesttow1"));
}






