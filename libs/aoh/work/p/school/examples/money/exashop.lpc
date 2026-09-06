/*
** Example-Shop
**
** Author: Thragor@Nightfall, 12apr94
** Update: Thragor@Nightfall, 22aug95
*/

inherit "/std/shop";

#include <rooms.h>
#include <properties.h>

public object article_useless()
// This function clones an object and configures it.
// Later it will be moved into the store.
{
  object ob;
  seteuid(getuid(this_object()));

  ob = clone_object("/std/thing");
  ob -> SetShort("a very useless item looking sometimes like that "
                 "and sometimes much more like this");
  ob -> SetLong("It should not be given to players.\n");
  ob -> SetIds(({"item"}));
  ob -> SetAds(({"useless","very","looking"}));
  ob -> SetValue(random(50)+50);
  ob -> SetWeight(100);
  ob -> Set(P_NOBUY,1); // no shop will buy this item again
  return ob;
}

public string article_random()
// This function returns an article which should be placed into
// the store by random.
// In this case only the filename is returned, the shop will clone
// the item by itself
{
  switch(random(5))
    {
     case 0:
      return "/std/weapon"; // the default weapon -> knife
     case 1:
      return "/std/armour"; // the default armour -> helmet
     case 2:
      return "/obj/torch";  // a torch
     case 3:
      return "/obj/sunglasses"; // sunglasses
     default:
      return "/obj/bag"; // a bag
    }
}

public status CheckTrade(object ob)
{
  return !ob->QueryMagic();	// we don't trade with magic items
}

public int ModifyPrice(object ob,int price,string verb)
// dwarves will get the double value if they sell items and
// will only pay the half plus a tax of the shopkeeper.
{
  int increase;
  increase = (int)(this_player()->QueryRace()=="dwarf")+1;
  if (verb=="sell")
    return price*increase;
  else if (verb=="buy")
    return (price/increase)+1000;
  return price;
}

public int GetMaxPrice()
// Dwarves may get 2000 cc at maximum, others 1000
{
  return 5000+1000*(int)(this_player()->QueryRace()=="dwarf");
}

public string detail_sign()
// give the normal sign-description with an additional text
{
  return (::detail_sign())+
    "\nAt the bottom of the sign you read: No credit.\n";
}

public void create()
{
  (::create());

  SetIntShort("The Example Shop");
  SetIntLong(
    "This is a boring 'normal'? example shop. It shows you some of "
    "the abilities of the shop.\n"
    "To take a look at the file, type 'ed "+object_name(this_object())+"'.\n");
  // Set the IntLong. 'A sign is placed on the counter.' will be placed
  // at the end of the file
  SetValuta(({"platinum","gold","silver"}));
  // we don't deal with copper coins
  // If no valuta are specified the default coins will be taken, i. e.
  // ({"platinum","gold","silver","copper"}) and in the near future
  // the cointypes set for a domain.
  // As soon as AddValuta is called, only those coins which will be
  // added will be accepted in the shop.
  SetSecurity(1);	// We don't allow anyone (except wizards) to enter
			// the store, even if the shopkeeper is dead.
  SetAppraise(0); // disable the command 'appraise' inside the shop
  SetBuy("acquire");
  // We don't want to 'buy' items, but 'acquire' them.
  SetLivingTrade(1); // we'll deal with livings, e. g. pets
  SetStore(0,
  // The first argument is the file to clone the store from.
  // If a file is specified, the store won't get it's default
  // settings, so you should not write "/std/store" there, when
  // you are not absolutely sure that you set all necessary data.
  // Well in fact, the necessary data are only those of a normal
  // /std/room.
  // If you give 0 as argument, the /std/store will be cloned and the
  // default settings will be made. In addition you may change some of
  // the settings with the following mapping:
    ([P_INT_LONG:
       "This is a wonderful example store where the longdescription is "
       "set by SetStore(0,<properties>) in the shop.\n",
      P_INT_SHORT:"Example Store",
      P_ITEMS_REFRESH:
        ({({"/std/thing",REFRESH_HOME,
            ([
              P_NOSELL:1, // The cupboard should not appear when 'list'
                          // is called in the store and it should not be
                          // sold
              P_SHORT:"a cupboard",
              P_LONG:"The shopkeeper puts some special items into it.\n",
              P_NOGET:"It is fixed to the ground.\n"
            ]),0})})
    ]));

  SetShopkeeper(0,
    ([P_SHORT:"a friendly shopkeeper",
      P_LONG:"This is the friendly shopkeeper of the Example Shop.\n",
      P_ADS:({"friendly"})
    ]));
  // Just as the store you may configure the Shopkeeper and (see below)
  // the dustbin

  SetDustbin(0,
    ([P_SHORT:"an awful looking dustbin",
      P_LONG:"This dustbin is really dirty.\n",
      P_ADS:({"dirty","awful","looking"})
    ]));

  SetDynamic(30);	// see below
  SetMinCash (30000);	// if we go below this point of money, add some
			// money depending on the dynamic-factor (s. a.)
			// In this case the money will be resetted (in the
			// reset of course, if it is below 30000 CU and
			// it will be restored to 30000*30/100 = 9000
  SetBuyFactor(400);	// You have to pay 400% of the value of an item

  AddArticle("/obj/torch",REFRESH_REMOVE,2);	// Add 2 torches to the store
  AddArticle("/obj/sunglasses",REFRESH_DESTRUCT);// Add a pair of sunglasses
  AddArticle(#'article_useless,REFRESH_REMOVE);
    // article_useless returns the objectpointer to an object
    // which should be moved into the store
  AddArticle(#'article_random,REFRESH_REMOVE);
    // article_random returns a file-name which should be cloned and
    // moved into the store afterwards
  AddArticle("/std/thing",REFRESH_DESTRUCT,5,
    ([P_SHORT:"a pencil",
      P_LONG:"This is just a normal pencil to show, how to add a normal "
             "/std/thing to the store by just settings its properties.\n",
      P_VALUE:10
    ]));

  AddExit("east","./tunnel");

}
