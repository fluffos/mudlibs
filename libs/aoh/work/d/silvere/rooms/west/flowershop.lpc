// A flower shop.
// created:      Auryn       [23-May-1999]



#include <silvere.h>
#include <properties.h>
#include <stdrooms.h>
#include <search.h>
#include <money.h>
#include <macros.h>

#define TS_NOMONEY    -1
#define ME           this_object()

inherit "/std/shop";

varargs void create()
{
   ::create();

   Set(P_INDOORS, 1);

   SetIntShort("a flower shop");
   SetIntLong(
"This shop is filled with a myriard of bright colours and intermingling "
"scents. Buckets, jugs and vases filled with flowers occupy every spot on "
"the shelves and on the floor, leaving only a narrow path from the door "
"to the counter. The floor is made from wooden planks, and the whitewashed "
"walls are adorned with pretty murals.\n");

SetShopkeeper("/d/silvere/npc/jehane");

   // this is a dumb workaround for the /std/shop counter

AddDetail("counter",
"The counter was built from bricks and whitewashed.\n");

AddDetail("bricks","The bricks making up the walls and the counter are "
"covered with whitewash.\n");

AddDetail("whitewash","Just some kind of white paint.\n");

AddDetail( ({"wall","walls"}),"The walls are painted white and decorated "
"with colourful murals, which are barely visible behind the shelves.\n");

AddDetail( ({"shelves","shelf"}),
  "Wooden shelves line the walls, filled with jugs and vases full of "
  "flowers.\n");

AddVItem(
	 ([ P_IDS: ({"murals","pictures"}),
	 P_ADS: ({"pretty","colourful"}),
	 P_LONG: "The walls have been painted with colourful pictures, "
	 "most of them showing flowers. Some of them look real enough to "
	 "be mistaken for some of the shop's wares.\n"
	  ]) );

AddDetail("wood",
  "The floor as well as most of the sparse furniture is made from wood.\n");

AddVItem(
	 ([ P_IDS: ({"planks","plank"}),
	 P_ADS: ({"scrubbed","wooden"}),
	 P_LONG: "The planks making up the floor have been scrubbed until "
	 "they are almost white.\n"
	  ]) );

AddDetail("furniture",
  "The furniture consists of some wooden shelves lining the wall and lots "
  "of containers for the flowers.\n");

AddVItem(
	 ([ P_IDS: ({"bucket","buckets"}),
	 P_ADS: ({"wooden","metal"}),
	 P_LONG: "Several buckets are standing around. Some are wooden, "
	 "others metal, but all are filled with lovingly arranged flowers.\n"
	  ]) );

AddVItem(
	 ([ P_IDS: ({"jug","jugs"}),
	 P_ADS: ({"earthenware","clay","glazed"}),
	 P_LONG: "Earthenware jugs are standing on the shelves, and larger "
	 "ones occupy the floor. The clay has been glazed and decorated "
	 "in bright colours, rivalling with those of the flowers that "
	 "have been carefully arranged in the containers.\n"
	  ]) );

AddVItem(
([ P_IDS: ({"vases","vase"}),
  P_ADS: ({"metal","clay","porcelain","etched","delicate","simple"}),
  P_LONG: "Vases of every variety can be seen around the shop: simple ones "
  "made from clay, elaborately etched metal ones and delicate porcelain "
  "vessels. They all hold colourful arrangements of flowers.\n"
  ]) );

AddDetail( ({"vessels","containers"}), "You see buckets, jugs and vases, "
"all of them filled with flowers.\n");


AddDetail("colours", "The flowers bloom in every colour of the rainbow, and "
"a few more besides.\n");

AddDetail("rainbow","That's just a metaphor, dummy... of course there is "
"no rainbow in here!\n");

AddDetail("flowers","The shop is filled with more different kinds of flowers "
"than you knew existed.\n");



Set(P_INT_SMELL,"The air is filled with the perfume of different kinds of "
"flowers. The fragrance is so intense it makes you slightly dizzy.\n");

   Set(P_SIGN_DESC,
      "A polished signboard reads: \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      "              JEHANE'S FLOWERS              \n"
      "           Bouquets made to order           \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );


   Set(P_HELP_MSG, #'detail_sign /*'*/);

   RemoveDustbin();

AddExit("north", SIL_WEST("westroad10"));


AddArticle("/d/silvere/obj/flowers/gardenia", REFRESH_RESET, 5);
AddArticle("/d/silvere/obj/flowers/black_rose",REFRESH_RESET, 2);
AddArticle("/d/silvere/obj/flowers/white_rose",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/yellow_rose",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/purple_rose",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/red_rose",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/pink_carnation",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/red_carnation",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/white_carnation",REFRESH_RESET, 3);
AddArticle("/d/silvere/obj/flowers/daisys", REFRESH_RESET, 5);
AddArticle("/d/silvere/obj/flowers/calla_lily",REFRESH_RESET, 3);



}
