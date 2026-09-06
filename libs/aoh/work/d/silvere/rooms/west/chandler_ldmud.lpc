// A chandler (candle shop) for the west of Silvere
// It sells candles... and ... uh...well candle.

// created:      Tune    [24-Apr-99]

#include <silvere.h>
#include <properties.h>
#include <stdrooms.h>
#include <search.h>
#include <money.h>
#include <macros.h>

inherit "/std/shop";

varargs void create()
{
   ::create();

   Set(P_INDOORS, 1);

   SetIntShort("Molly's Chandler");
   SetIntLong(
     "The interior of this small shop is quite cramped, as stacks "
     "and stacks of candles are piled up in heaps, in corners, on "
     "shelves, hanging from rafters, and every imaginable space. The "
     "shop smells sweetly of fresh wax and other fragrant scents.\n");

   AddVItem(
    ([ P_IDS : ({ "candles", "tapers" }),
       P_ADS : ({ "wax", "tallow", "beeswax" }),
       P_LONG : "Freshly dipped candles are everywhere.\n",
       P_SMELL : "Fragrant fresh wax and other scents.\n",
     ]) );

   // this is a dumb workaround for the /std/shop counter
   AddDetail("counter",
     "(Add a counter here if you want one\n");


   SetIntSmell("Smells of tallow.\n");

   Set(P_SIGN_DESC,
      "A rough signboard reads: \n"
      " ~ Molly's Chandler ~ \n"
      "Original hand-dipped candles for all prices and tastes.\n");

   Set(P_HELP_MSG, #'detail_sign /*'*/);

   AddArticle("/d/silvere/obj/chandler/tallow", REFRESH_RESET, 6);
   AddArticle("/d/silvere/obj/chandler/wax", REFRESH_RESET, 8);

   RemoveDustbin();

   AddExit("south", SIL_WEST("westroad3"));

}

// ----------------------------------------------------------------------
//  CheckTrade()
// ----------------------------------------------------------------------
//  Special check for chandler shop.
//  Molly only deals in light sources.
// ----------------------------------------------------------------------

int CheckTrade(object ob)
{
   if( ({int})ob->id("candle") || ({int})ob->id("light") || ({int})ob->id("torch") || ({int})ob->id("lamp") )
        return 1;
}
