// A small butcher shop for the west area of Silvere
// This shop only deals with items if they have an id of
// "corpse" or "meat".

// created:      Tune    [06-May-98]
// modified:     Tune    [27-may-98]

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

   SetIntShort("a butcher shop");
   SetIntLong(
     "The bloody smell of hacked-up carcases predominates this "
     "little butcher shop. A long counter holds some packets of "
     "fresh meat. Strings of sausages hang from a rack at the "
     "back of the shop. A door behind the counter leads out to "
     "the slaughterhouse. Barrels of salt are stacked up in a "
     "corner.\n");

   AddVItem(
    ([ P_IDS : ({ "sausages", "sausage" }),
       P_ADS : ({ "meat", "pink", "grey" }),
       P_LONG : "Lovely greasy sausage links, grey and pink, white and "
                "brown, dangle from a large wooden "
                "display rack. The soft, oblong ones were probably "
                "made up this week, while the harder, dry wrinkled ones "
                "have been smoked.\n",
       P_SMELL : "Greasy, spicy, and very meaty.\n", // something better..
    ]) );

   AddVItem(
    ([ P_IDS : ({ "flies" }),
       P_LONG : "Small clouds of flies hover over the meat counter.\n",
       P_NOISE : "Flies hum and buzz around the packets of meat.\n"
    ]) );

   // this is a dumb workaround for the /std/shop counter
   AddDetail("counter",
     "The meat counter displays a rather nice selection of "
     "packets of meat on ice, all wrapped up in brown paper. "
     "A sign is propped up on one end of the counter which "
     "advertises a list of meats for sale and prices.\n");

   AddVItem(
    ([ P_IDS : ({ "counter" }),
       P_ADS : ({ "long", "wooden", "meat" }),
       P_LONG: "The meat counter displays a rather nice selection of "
               "packets of meat on ice, all wrapped up in brown paper. "
               "A sign is propped up on one end of the counter which "
               "advertises a list of meats for sale and prices.\n"
     ]) );

   SetIntSmell("The smell of salt and slightly rancid scraps of meat "
               "is quite strong.\n");

   Set(P_SIGN_DESC,
      "A crudely chalked up board reads: \n"
      "~ Bilben's Butcher Shoppe ~\n"
      "Specials today are salted gorgon hocks, rat mince pie, orc blood sausages.\n"
      "We buy all manner of corpses or trade for dried meat. \n");

   Set(P_HELP_MSG, #'detail_sign /*'*/);

   AddArticle("/d/silvere/obj/food/orc_sausage", REFRESH_RESET, 6);
   AddArticle("/d/silvere/obj/food/rat_pie", REFRESH_RESET, 6);
   AddArticle("/d/silvere/obj/food/gorgon_hock", REFRESH_RESET, 6);
   AddArticle("/d/silvere/obj/food/vulture_koftas", REFRESH_RESET, 6);

   RemoveDustbin();

 /*   ideas for more details:
    chopping board
    butcher with very sharp knife
    salt
    ice
 */

}

void init()
{
   ::init();
   add_action("do_trade", "trade");
}


// ----------------------------------------------------------------------
//  do_trade()
// ----------------------------------------------------------------------
//  The butcher will "prepare" corpses for players.
//  The player gives a corpse to the butcher, who will chop it up
//  and return some packets of meat to the player (/std/food).
//
//  THIS AIN'T DONE YET - but i'm workin' on it
// ----------------------------------------------------------------------


int do_trade(string str)
{
   mixed found;
   string msg, emsg;

   if(!str)
   {
     return notify_fail(    // I appologize for "Thragor-code"...
       lambda(0,
         ({
           SF(SkSay),
           CustomerName()+", what do you want to trade? I only "
             "accept corpses in trade for packets of dried meat.\n"
         }) ),
       NOTIFY_NOT_VALID),0;
   }

   found = searchm(TP,str, SEARCH_INV|SM_CMULTI|SM_REALLY|WizSearch());
   found = sort_findings(found, sort_f_prop(P_NODROP));

   dtell("tune", sprintf("Found is: %O\n\n", found));

   msg = found[-FOUND_SINGLE]
        ? "You don't have that many " + str + "s.\n"
        : "";
   emsg = found[-FOUND_SINGLE]
         ? CustomerName(1)+
           " didn't find as many things as "+({string})TP->QueryPronoun()+
           " wanted to trade.\n"
         : "";


   return 1;
}
/*
          Pcurrentobjects = ok;
          AdjustMoney(TP,m_array = (mixed *)MONEY_DEMON->CreateMoney(amount,
                                                           QueryValuta()),0);
          Pcurrentobjects = 0;
          Write(
            SkShort(1)+" takes "+print_list(ok)+
            " from you and gives "+MONEY_DEMON->QueryMoneyString(m_array)+
            " to you.\n",1);
          Say(
            ({SkShort(1)+" takes "+print_list(ok)+
              " from "+CustomerName()+" and gives "+
              MONEY_DEMON->QueryMoneyString(m_array,10)+" to "+
              TP->QueryObjective()+".\n",
              "Something happens.\n"

*/
// ----------------------------------------------------------------------
//  CheckTrade()
// ----------------------------------------------------------------------
//  Special check for butcher shop.
//  The butcher only buys/sells meat or corpses.
// ----------------------------------------------------------------------

int CheckTrade(object ob)
{
   if( ({int})ob->id("corpse") || ({int})ob->id("meat") )
        return 1;
}

// ----------------------------------------------------------------------
//  TestSell()
// ----------------------------------------------------------------------
//  special checks for corpses :
//  the passed value of 'price' will be 0 for corpses (since
//  corpses are usually without value)
//  we override the checks if it ids to a corpse, otherwise
//  call the normal checks in ::TestSell
// ----------------------------------------------------------------------


protected int TestSell( object ob, int price )
{
   if( QueryCash() < 1 )
     return TS_NOMONEY;

   if( ({int})ob->id("corpse") )
     return ({int})ob->QueryWeight() / 7000;   // 1 copper coin per 7kg
   else
     return ::TestSell(ob, price);
}



