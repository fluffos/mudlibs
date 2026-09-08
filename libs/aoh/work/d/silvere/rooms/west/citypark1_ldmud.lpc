// This road leads to the citypark
// created:       Sonic    [30-May-1997]
// last changed:  Sonic    [01-Jul-1997]  added region/coordinates
//                Auryn    [27-Apr-1999]  added description, details


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
   Set(P_INT_SHORT,"Park Lane");
   Set(P_INT_WIZMSG,
" NORTH: Back to the mainroad.\n\
 SOUTH: The road continues to the citypark, another newbie area\n");

   Set(P_INT_LONG,
"You are walking along Park Lane which runs parallel to the city wall. "
"Far off to the north, you can see Westway, the city's main road. South, "
"you glimpse trees and bushes and the entrance to the city park. The "
"houses here are small and rather plain. @@TimeMsg@@ \n");

   Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG:"Around you, people are going after their daily "
"business. Children are playing, and some women are standing together in "
"one of the doors, chatting.",
      NIGHT_DEFAULT_MSG:"It is night, and there is nobody to be seen on "
"the street.",
      ND_SUNSET:"As the sun is setting, you see people returning to their "
"homes after the day's work.",
      ND_DAWN:
        "The street is still empty, although in the houses around you "
"people are beginning to stir.",
      ND_SUNRISE:
        "As the sun rises, people start emerging from the houses."
   ]) );

   AddVItem(
	    ([ P_IDS:({ "street", "lane" }),
	    P_ADS:({"small", "narrow", "paved"}),
	    P_LONG:
	    "Park Lane is a rather narrow street paved with cobblestones. "
	    "In this part, it isn't kept as neat and clean as farther north. "
	    "Refuse is piling in some of the corners, more or less out of "
	    "sight but still noticeable.\n"
	     ]) );

   AddDetail( ({"stones","cobblestones","pavement"}),"The lane is paved with "
   "cobblestones. They are none too clean and rather uneaven. Weeds are "
   "growing between them.\n");

   AddDetail("weeds","Weeds are growing in the fissures in the pavement.\n");

   AddDetail( ({"fissures","spaces"}),"The fissures between the cobblestones "
   "are filled with dirt. Weeds are growing there.\n");

   AddDetail("dirt","Dirt is filling the spaces between the cobblestones, "
	     "providing ample nourishment for the weeds growing there.\n");

   AddDetail( ({"refuse","corners"}),"Some of the houses' inhabitants just "
   "dumped their refuse in some corners.\n");

   AddVItem(
	    ([ P_IDS:({"wall","city wall"}),
	    P_ADS:({"high"}),
	    P_LONG:
	    "The high wall surrounding the city runs parallel to the street.\n"
	     ]) );

     AddDetail("children","You see some children playing on the street.\n");

     AddDetail("women","Some women are standing in one of the doors, having "
	     "a chat.\n");

   AddVItem(
	    ([P_IDS:({"westway","road"}),
	    P_ADS:({"main"}),
	    P_LONG:
	    "Westway is the main road running through Silvere. It offers a "
	    "wide variety of shops and other ways to spend your hard-earned "
	    "coins.\n"
	     ]) );

   AddDetail( ({"bushes","trees"}),"You can just make out some trees and "
   "bushes forming the entrance of the city's low level adventurers' park.\n");

   AddDetail( ({"park","city park","adventurers' park"}),
	      "Just follow this street south and you'll find it.\n");

   AddVItem(
	    ([P_IDS: ({"houses","buildings"}),
	    P_ADS: ({"small","plain"}),
	    P_LONG:
	    "While the houses around you cannot really be called shabby, "
	    "most of them could definitely do with some fresh paint and a "
	    "thorough cleaning.\n"
	     ]) );

   Set(P_SMELL,"A faint reek of mostly organic waste hangs in the air.\n");


   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -180,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("north",SIL_WEST("cityinfo1"));
   AddExit("south",SIL_WEST("citypark2"));
}
