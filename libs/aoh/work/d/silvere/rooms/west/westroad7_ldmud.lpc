// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added regions/coordinates
//                Auryn    [19-May-1999]  description, details


#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <nightday.h>
inherit SILBASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Westway. A street leads north to the council hall");
   Set(P_INT_LONG,
"You have reached another intersection. To the north starts Elrimand Road. "
"Elrimand was the founder and first Lu'meyn of Silvere. The street that bears "
"his name runs to the council hall. South of you is the entrance to a small "
"tailor's shop. @@TimeMsg@@\n");

   Set(P_TIME_MSG,
       ([DAY_DEFAULT_MSG: "The streets are quite crowded with people "
       "going about their daily business. The shops are open, and the "
       "city is brimming with life.",
       NIGHT_DEFAULT_MSG: "The city seems to be asleep. Nobody is to be "
       "seen on the streets. The shops are closed, and all the windows "
       "are dark.",
       ND_SUNRISE: "As the sun rises, the merchants open their shops. "
       "People start emerging from the houses and the streets are slowly "
       "filling with life.",
       ND_SUNSET: "The merchants start closing their shops for the night. "
       "The last rays of the setting sun fall on the slowly emptying streets."
	]) );

   AddDetail( ({"road","elrimand road"}),
	      "It starts north of you and leads to the council hall. Like "
	      "Westway, it is paved with large flagstones.\n");

   AddVItem(
	    ([ P_IDS: ({"flagstone","flagstones","stone","stones"}),
	    P_ADS: ({"large"}),
	    P_LONG: "The streets here in the centre of the city are paved "
	    "with large flagstones, which are swept every day by city "
	    "workers.\n"
	     ]) );

   AddDetail( ({"hall","council hall"}),"You can't see it from here.\n");

   AddDetail( ({"entrance","door"}),"The door to the tailor's shop has been "
   "painted bright red. A sign is hanging above it.\n");

   AddVItem(
	    ([P_IDS:({"sign"}),
	    P_LONG: "The sign shows a picture of a needle and thread. "
	    "Something is written beneath it.\n",
	     P_READ_MSG:"Couture Celimarith \n"
	     ]) );

   AddVItem(
	    ([P_IDS:({"shop","house","building"}),
	    P_ADS: ({"small"}),
	    P_LONG: "This small house is painted in a light, pastel orange "
	    "hue. The door is bright red, with a sign above it.\n"
	     ]) );


   Set(P_INT_WIZMSG,
" NORTH: To the council hall.\n\
 WEST:  to the harbour and the temple of Xalandre.\n\
 EAST: deeper into the city (towards the palace)\n\
 SOUTH: tailor's shop\n");


   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -120,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("north",  SIL_WEST("councilroad1"));
   AddExit("west",   SIL_WEST("westroad6"));
   AddExit("east",   SIL_WEST("westroad8"));
   AddExit("south",  SIL_WEST("tailor"));
}

