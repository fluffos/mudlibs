// A fishmongers. hey, Silvere's a harbour town
// It sells fish, dried and smoked (and maybe fresh?)

// created:      Tune    [24-Apr-99]
// changed:      Auryn   [16-May-1999]     description, details and some
//                                         items to buy here


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

   SetIntShort("a fishmonger's");
   SetIntLong(
   "The walls and floor of this little shop are covered with brightly painted "
   "glazed tiles. A counter runs along one of the walls, filled with large "
   "vats full of ice. In them, several varieties of fresh fish are displayed. "
   "Behind the counter, dried and smoked fish are hanging on strings from the "
   "ceiling. A large barrel holds kippers, smoked and salted herrings, while "
   "another one is filled with salt.\n");
   AddVItem(
    ([ P_IDS : ({ "fish" }),
       P_ADS : ({ "fresh", "dried", "salted", "smoked" }),
       P_LONG : "Dried and salted fish are hanging behind the counter, while "
                "fresh ones are stored in ice.\n",
       P_SMELL : "You cannot distinguish the various kinds of fish by their "
                 "smell. Everything smells, well, fishy.\n",
   ]) );
   // this is a dumb workaround for the /std/shop counter
   AddDetail("counter",
   "The counter is quite large and occupied by several large, ice-filled "
   "vats.\n");
   AddDetail( ({"wall","walls","floor"}),"The walls and floor are covered with "
   "glazed tiles, probably to make them easier to keep clean.\n");
   AddVItem(
   ([ P_IDS: ({"tiles"}),
      P_ADS: ({"glazed","large","painted","bright","brightly painted"}),
      P_LONG: "The large tiles have been painted in bright colours. They show "
      "different kinds of fish as well as other inhabitants of the sea, like "
      "mermaids. Not two of them seem to display the same picture.\n"
   ]) );
   AddDetail(({"picture", "pictures"}),"The pictures of fish, mermaids and other "
   "creatures are painted in bright colours. Not two of them are alike.\n");
   AddDetail( ({"mermaids","creatures"}),
   "They are only pictures on the tiles.\n");
   AddVItem(
   ([ P_IDS: ({"vat","vats"}),
      P_ADS: ({"large","ice-filled"}),
      P_LONG: "Large vats full of ice hold the fresh fish displayed in the counter.\n"
   ]) );
   AddDetail("ice","The ice in the vats keeps the fish fresh. You have no idea "
   "how Feridwyn keeps it from melting away during summer.\n");
   AddDetail("strings","You see some dried fish hanging on strings behind the "
   "counter.\n");
   AddVItem(
   ([ P_IDS: ({"barrel","barrels"}),
      P_ADS: ({"large","big","wooden"}),
      P_LONG: "You see two big wooden barrels standing behind the counter. One of "
      "them holds some smoked and salted herrings, which are often bought by "
      "adventurers for travelling rations. The other one is filled with salt.\n"
   ]) );
   AddVItem(
   ([ P_IDS: ({"kippers","herrings"}),
      P_ADS: ({"salted","smoked"}),
      P_LONG: "One of the barrels contains smoked and salted herrings.\n"
   ]) );
   AddDetail("salt","The salt is needed to prepare the fish so it can be stored "
   "or used for travelling rations.\n");
   SetIntSmell("It smells of fish, of course. You noticed that even before you "
   "entered the shop.\n");
   Set(P_SIGN_DESC,
      "A rough signboard reads: \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      "            FERIDWYN'S SEAFOOD              \n"
      " Offers you a fine selection of fish and    \n"
      "  other delicacies - caught fresh daily!    \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );

   Set(P_HELP_MSG, #'detail_sign /*'*/);
   AddExit("south", SIL_WEST("westroad6"));
   AddArticle("/d/silvere/obj/fish/haddock", REFRESH_RESET, 6 );
   AddArticle("/d/silvere/obj/fish/salmon" , REFRESH_RESET, 4 );
   AddArticle("/d/silvere/obj/fish/kipper", REFRESH_RESET, 6 );
   AddArticle("/d/silvere/obj/fish/shrimp", REFRESH_RESET, 2 );
   RemoveDustbin();
   SetShopkeeper("/d/silvere/npc/feridwyn");
}
