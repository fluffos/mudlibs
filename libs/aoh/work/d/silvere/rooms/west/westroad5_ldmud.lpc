// A long, wide road from the gates to the west toward the palace
// created:       Sonic    [29-May-1997]
// last changed:  Sonic    [01-Jul-1997]  Added regions/coordinates
//                Auryn    [13-May-1999]  description, details


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
   Set(P_INT_SHORT,"Westway. A street leads north to the post office.");
   Set(P_INT_LONG,
"You are still strolling along Westway, a wide, paved boulevard leading "
"through the heart of Silvere. A narrow street branches off to the north. "
"The houses lining the street are painted in vivid, friendly colours, "
"with intricate decorations displaying the wealth of their owners. "
"@@TimeMsg@@ \n");


   Set(P_INT_WIZMSG,
" NORTH: to the postoffice.\n\
 WEST:  to the harbour and the temple of Xalandre.\n\
 EAST:  deeper into the city.\n");

Set(P_TIME_MSG,
    ([ DAY_DEFAULT_MSG: "The many shops along the boulevard are open. All "
                        "around you, people are going after their business, "
                        "filling the streets with life.",
    NIGHT_DEFAULT_MSG:  "It is night, and the streets are empty.",
    ND_SUNRISE:         "The shops are still closed, but as the sun rises, "
                        "the first people start emerging from their houses.",
    ND_SUNSET:          "As the sun sets, the merchants close their shops."
     ]) );

AddVItem(
	 ([ P_IDS: ({"westway","boulevard"}),
	 P_ADS: ({"wide","paved"}),
	 P_LONG:
	 "Westway is the main street of this part of Silvere. It is paved "
	 "with large, smooth flagstones, which are swept clean every day. "
	 "Brightly painted houses line the boulevard, many of them with "
	 "shops on the ground floor.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"flagstones","pavement","stones"}),
	 P_ADS: ({"large","smooth"}),
	 P_LONG:
	 "The pavement is swept daily by city workers. As long as you "
	 "stay on the main street, your feet won't get dirty, except during"
	 "really foul weather.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"street"}),
	 P_ADS: ({"narrow"}),
	 P_LONG:
	 "A narrow street branches off Westway, leading north.\n"
	  ]) );

AddDetail("houses","Most of the houses along Westway are owned by rich "
	  "merchants, and have shops on the ground floor. They are all "
	  "painted in bright colours, with many decorations to show that "
	  "their owners are well off.\n");

AddDetail("shops","Many shops can be found along Westway, offering just "
	  "about everything you can imagine (and possibly even a few things "
	  "you can't.)\n");

AddVItem(
	 ([ P_IDS: ({"colours"}),
	 P_ADS: ({"bright","vivid","friendly"}),
	 P_LONG:
	 "The houses have been painted brightly and decorated with beautiful "
	 "ornaments.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"decorations","ornaments"}),
	 P_ADS: ({"beautiful","intricate"}),
	 P_LONG:
	 "Intricate ornaments adorn many of the houses. Most of them show "
	 "maritime scenes.\n"
	  ]) );

AddDetail(({"scenes","maritime scenes"}),"Since Silvere is a harbour city, "
"most of the houses' decorations show maritime scenes.\n");

   Set(P_INT_MAP,"silvere1");
   Set(P_REGION,REGION_CITY);
   Set(P_COORDINATES, ({ ({ -140,10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");
   AddExit("west",   SIL_WEST("westroad4"));
   AddExit("east",   SIL_WEST("westroad6"));
   AddExit("north",  SIL_WEST("wpostroad1"));
}

