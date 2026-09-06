
// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [01-Jun-1997]
// last changed:  Sonic    [01-Jul-1997]  Added regions/coordinates
//                Auryn    [16-May-1999]  description, details

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
   Set(P_INT_SHORT,"Westway. A fishmonger's shop is to the north");
   Set(P_INT_LONG,
"A faint but distinctive smell wafts out of the house north of you. You are "
"standing outside a fishmonger's shop. @@TimeMsg@@ You can follow Westway "
       "west towards the harbour, or east to the palace.\n");

   Set(P_INT_WIZMSG,
" WEST:  to the harbour and the temple of Xalandre.\n\
  EAST: deeper into the city\n\
  NORTH: fishmonger's shop\n");

AddVItem(
  ([ P_IDS: ({"shop","house","building","shop front","front"}),
  P_LONG:
  "The shop north of you has been decorated with nets, fishing rods and "
  "other fisherman's tools of trade. A distinct smell of fish emanates "
  "from there. A sign hangs above the door.\n"
   ]) );

AddDetail(({"net","nets"}),"The nets contain some dried starfish, which "
"seem to be real ones, as well as carved wooden fishes which have been "
" painted in lifelike colours.\n");

AddVItem(
	 ([P_IDS: ({"rods","rod","tools" }),
	 P_ADS: ({"fishing"}),
	 P_LONG:
	 "Fishing rods and other tools have been used to decorate the shop "
	 "front.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"starfish"}),
	 P_ADS: ({"dried","real"}),
	 P_LONG:
	 "Some dried starfish have been tied to the nets for decorations.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"fish"}),
	 P_ADS: ({"carved","wooden","painted"}),
	 P_LONG:
	 "The wooden fishes have been painted to look like real ones.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"sign"}),
	 P_ADS: ({"square","wooden","painted"}),
	 P_LONG:
	 "Above the door, you see s square wooden sign which has been painted "
	 "with the picture of a salmon.\n",
	 P_READ_MSG: "The sign reads: 'Feridwyn's Seafood'"
	  ]) );

AddDetail( ({"salmon","picture"}),"A picture of a salmon has been painted "
"on the sign.\n");

AddDetail( ({"westway","boulevard"}),"You are strolling along Westway, "
"Silvere's main boulevard.\n");


   Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG: "All around you, people are going about their "
    "business. Westway is the heart of Silvere, and during daytime the "
"boulevard is pulsing with life.",
    NIGHT_DEFAULT_MSG:  "It is night, and the streets are empty.",
    ND_SUNRISE:         "The shops are still closed, but as the sun rises, "
                        "the first people start emerging from their houses.",
    ND_SUNSET:          "As the sun sets, the merchants close their shops."
     ]) );

   Set(P_INT_SMELL, "The air smells slightly of fish. The source of the "
       "odour seems to be located in the shop north of you.\n");
   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -130,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("west",   SIL_WEST("westroad5"));
   AddExit("east",   SIL_WEST("westroad7"));
   AddExit("north",  SIL_WEST("fishmonger"));
}

