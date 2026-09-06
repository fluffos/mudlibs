// A wine shop.

// created:      Auryn       [20-May-1999]



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

   SetIntShort("a wine merchant's shop");
   SetIntLong(
"The interior of this shop is furnished entirely with wood. A slightly "
"musty smell hangs in the air. Racks filled with dozens of bottles line the "
"walls. Behind the counter, you notice several large barrels. Three small "
"round tables are standing next to the counter, for those customers who "
"want to sample the wares before buying larger quantities. \n");



SetShopkeeper("/d/silvere/npc/brigan");

   // this is a dumb workaround for the /std/shop counter

AddDetail("counter",
"The counter was built from large barrels which have been cut in half and "
"topped with smooth, polished boards.\n");

AddDetail( ({"wall","walls","floor"}),"The walls and floor are panelled with "
"wood, which has been polished to a silky sheen.\n");

AddDetail("racks",
  "Wooden racks line the walls, filled with lots of bottles.\n");

AddDetail("wood",
  "Some dark wood has been used for the furniture and panelling. It has "
"been carefully polished.\n");

AddDetail(({"furniture","panelling","panels"}),
  "Th furniture looks rather old. Like the panels used for the floor and "
"walls, every piece has been lovingly polished. It seems Brigan takes some "
"pride in his shop.\n");

AddDetail("bottles","The bottles are carefully labelled. Some of them look "
"quite dusty.\n");

AddVItem(
([ P_IDS: ({"table","tables"}),
  P_ADS: ({"small","high","round","wooden"}),
  P_LONG: "Three round tables have been placed near the counter. There "
  "are no chairs, but the tables are high enough that an anverage human can "
  "comfortably stand at them and have a drink.\n"
  ]) );

AddVItem(
([ P_IDS: ({"barrel","barrels"}),
  P_ADS: ({"large","big","wooden"}),
  P_LONG: "You see several large wooden barrels behind the counter. They are "
"not labelled, yet Brigan probably knows what is inside each of them.\n"
]) );

   SetIntSmell("The air smells slightly musty, of old wine, cork and dust.\n");

   Set(P_SIGN_DESC,
      "A polished signboard reads: \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
      "                CHEZ BRIGAN                 \n"
      "         SUPPLIER OF EXCELLENT WINES        \n"
      "       Rare Vintages - Export & Import      \n"
      "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" );


   Set(P_HELP_MSG, #'detail_sign /*'*/);

   RemoveDustbin();

AddExit("south", SIL_WEST("westroad8"));


 AddArticle("/d/silvere/obj/wine/chamglass", REFRESH_RESET,5);
 AddArticle("/d/silvere/obj/wine/champagne", REFRESH_RESET,3);
 AddArticle("/d/silvere/obj/wine/wineglass", REFRESH_RESET,5);
 AddArticle("/d/silvere/obj/wine/elfwine", REFRESH_RESET,5);



}

