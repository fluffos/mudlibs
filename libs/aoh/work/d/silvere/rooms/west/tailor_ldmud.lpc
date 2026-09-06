// A tailor shop. It will (hopefully) make custom clothes.

// created:      Tune    [25-Apr-99]

#include <silvere.h>
#include <properties.h>
#include <stdrooms.h>
#include <search.h>
#include <money.h>
#include <macros.h>

#define ME           this_object()

inherit "/std/shop";

varargs void create()
{
   ::create();

   Set(P_INDOORS, 1);

   SetIntShort("a tailor shop");
   SetIntLong(
     "A tailor. She creates fine clothes, tailored to your "
     "specifications. Bolts of fine cloth lay stacked upon painted "
     "shelves. A dressmaker's dummy stands in one corner.\n");


   AddVItem(
    ([ P_IDS : ({ "cloth" }),
       P_ADS : ({ "fine" }),
       P_LONG : "Fine silks, damask, linens, and heavy brocades "
                "dazzle the eyes and challenge the pocketbook.\n",
       P_SMELL : "It, well, smells like cloth.\n",
     ]) );

   // this is a dumb workaround for the /std/shop counter
   AddDetail("counter",
     "(Add a counter here if you want one\n");


   SetIntSmell("what does a tailor shop smell like?\n");

   Set(P_SIGN_DESC,
      "A painted signboard reads: \n"
      "   Tailor       \n"
      "All manner of clothes finished to your specification.\n");

   Set(P_HELP_MSG, #'detail_sign /*'*/);

// AddArticle("/d/silvere/obj/  .....   , REFERSH_RESET, .... );

   RemoveDustbin();

   AddExit("north",  SIL_WEST("westroad7"));

}
