/*
** The central adventurers shop
**
** This is also an example to show the new possibilities of the /std/shop.
** It uses most of its functions.
**
** Update: Thragor@Nightfall, 23may96
*/

inherit "/std/shop";

#include <rooms.h>
#include <combat.h>
#include <properties.h>
#include <combat.h>
#include <living.h>
#include "path.h"

public object article_amulet()
// This function clones an object and configures it.
// Later it will be moved into the store.
{
  object ob;
  ob = clone_object("/std/armour");
  ob->SetShort("a small glowing amulet");
  ob->SetLong(
    "The chain of the amulet is made of ivory. On each chain link you see "
    "small strange symbols. You're not quite sure, if these are letters or "
    "just small decorations.\n"
    "The pendant is made of ivory, too. Some symbols are engraved on it, "
    "inlaid with platinum. A big ruby in the middle of it glows in a dark "
    "red light.\n"
    "Two feathers, obviously from an eagle surround the pendant.\n");
  ob->SetInfo(
    "Those symbols are magic symbols. Perhaps a magician might "
    "identify them.\n");
    // this is the normal info everyone can get, e. g. in this shop
  ob->SetMagic(
    "It's a very old charm and all symbols can't be identified, but it "
    "seems to protect from an elemental force. And the opposite element "
    "seems to be banned into this stone on the pendant.\n");
    // this is a magic info, only special spells can query
  ob->SetArmourType(AT_AMULET);
  ob->SetAC(0);
  ob->SetDefence(DT_COLD,20);
  ob->SetLight(20);
  ob->SetAPperQP(100);
  ob->SetReadMsg("@l<!uR&... and many other strange symbols.\n");
  ob->SetAds(({"ivory","magic","small","glowing"}));
  ob->SetValue(1358);
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

public int ModifyPrice(object ob,int price,string verb)
// adventureres will pay 1/3 less then other for items
{
  if (this_player()
      && this_player()->QueryGuild()=="adventurer"
      && verb=="buy")
    return price*2/3;
  return price;
}

public int GetMaxPrice()
// Adventurers may get 2000 cc at maximum, others 1000
{
  return 4500+500*((int)(this_player()&&
                     this_player()->QueryGuild()=="adventurer")+1);
}

public string detail_sign()
// give the normal sign-description with an additional text
{
  return (::detail_sign())+
    "\nAt the bottom of the sign you read:\n"
    "           No credit.\n"
    " Adventurers will get a discount.\n";
}

public void create()
{
  (::create());
  SetIntShort("The Adventurer Shop");
  SetIntLong(
    "You're in the famous adventurer shop of Nightfall in the capital "
    "Nightfall City. The shop is well known for its big traffic and "
    "the enormous list of items it can offer very often. And what is "
    "more: Rumours tell that the shopkeeper has a contract with the "
    "Nightfall CityBank, so that he has always enough money to buy "
    "new items.\n"
    "A small corridor leads west into a special storage room.\n");
  AddDetail(({"famous adventurer shop","adventurer shop","shop"}),
    "Some say it was a gift of the gods that this shop hadn't been "
    "destroyed, while Nightfall City was destroyed some years ago.\n");
  AddDetail("nightfall",
    "This is the MUD, where you can find such wonderful shops like this.\n");
  AddDetail(({"nightfall city","city","capital"}),
    "Now it's again a proud and rich city. The bards sing about the "
    "Armageddon Day which once hit the capital of Nightfall.\n"
    "But the gods decided to give this town a second chance and now "
    "it is reborn with a new face.\n");
  AddDetail(({"traffic","big traffic"}),
    "You can see many souvenirs from all over Nightfall in this shop, "
    "which content customers gave as gift to the shopkeeper.\n");
  AddDetail(({"enormous list","list of items","list","items"}),
    "Sometimes there are many items in the store. Just try 'list' to "
    "see if the shopkeeper again did a good job.\n");
  AddDetail(({"rumours","rumour"}),
    "You know many rumours about this shop. Some say that the shopkeeper "
    "is a demi-god, some say that he destroyed Nightfall City once, so that "
    "he can sell more, bards sung about his glorious victory when he fought "
    "against the thieves in Nightfall City.\n"
    "But noone was ever able to proove one of these romours.\n");

  // The following AddValuta will tell the shop which coins to use to trade.
  // In this case the call is obsolete, because the default settings for
  // the domain archwiz is platinum, gold, silver and gold. It's just here
  // to show you how to call it.
  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  AddArticle("/obj/torch",REFRESH_REMOVE,6);
  // Add six torches
  AddArticle(#'article_amulet,REFRESH_REMOVE,
    ([P_SIZE:PSIZE_SMALL]));
  AddArticle(#'article_amulet,REFRESH_REMOVE,
    ([P_SIZE:PSIZE_NORMAL]));
  AddArticle(#'article_amulet,REFRESH_REMOVE,
    ([P_SIZE:PSIZE_LARGE]));
  // add the special amulets in three different sizes
  AddArticle(#'article_random,REFRESH_REMOVE);
  AddArticle(#'article_random,REFRESH_REMOVE);
  AddArticle(#'article_random,REFRESH_REMOVE);
  AddArticle(#'article_random,REFRESH_REMOVE);
  AddArticle(#'article_random,REFRESH_REMOVE);
  AddArticle( "/players/mica/dp/weapons/darkportal/c_bow", REFRESH_REMOVE, 2 );
  AddArticle( "/players/mica/mule/dummymule", REFRESH_REMOVE, 3 );
  AddArticle( "/players/mica/mule/curry-comb", REFRESH_REMOVE, 3 );
  AddArticle( "/players/mica/dp/weapons/darkportal/m_bow", REFRESH_REMOVE, 2 );
  AddArticle( "/players/mica/dp/objects/darkportal/m_arrow", REFRESH_REMOVE, ([ P_AMOUNT : 2000 ]) );
  AddArticle( "/players/mica/dp/objects/darkportal/wiquarrel", REFRESH_REMOVE, ([ P_AMOUNT : 1000 ]) );
  // add one random article (kicking this turtle was Cadra's favourite 
  // expression of anger)
  AddArticle("/std/thing",REFRESH_REMOVE,
    ([
      P_SHORT:"a long-forgotten, invisible, dead turtle",
      P_LONG:"The turtle has some strange dents in its shell.\n",
      P_IDS:({"turtle","animal"}),
      P_ADS:({"invisible","dead","long-forgotten","forgotten"}),
      P_VALUE:1,
      P_WEIGHT:250,
      P_NOBUY:1,
      P_NOISE:"You hear nothing, the turtle seems to be dead.\n",
      P_SMELL:"Smells like a dead turtle.\n"
    ]));
  AddArticle("/std/weapon",REFRESH_REMOVE,
    ({
      ([ P_STANDARD : ({ WT_AXE, 5 }) ]),
    ([
      P_SHORT:"a pickaxe",
      P_LONG:"It's a pickaxe *shrug*.\n",
      P_IDS:({"axe","pickaxe"}),
      P_VALUE:1,
      P_WEIGHT:250,
      P_NOBUY:1
    ]) }), 5 );
  // This article is a dummy. The listed commands are in fact
  // a built-in of the player. But players can remember it this
  // way easier.
  AddArticle("/std/thing",REFRESH_REMOVE,
    ([
      P_SHORT:"a feedback",
      P_LONG:"A small gem, made from polished jade. On its surface there "
             "is an engraving of two circles connected in a circle "
             "by arrows.\n",
      P_IDS:({"feedback", "feed back", "gem"}),
      P_ADS:({"polished", "small", "jade"}),
      P_VALUE:1,
      P_WEIGHT:5,
      P_NOISE:"You hear nothing.\n",
      P_SMELL:"Smells like a polished jade gem (big surprise).\n",
      P_HELP_MSG:"Feedback is important for any game. In Nightfall you have "
                 "the commands 'bug', 'idea', 'laud', 'typo' and 'creator' "
                 "available to give feedback. Use the 'help' command to "
                 "find out more, e.g. 'help creator'.\n"
    ]));
  // add one article and set all its properties
  SetDustbin(0,
  // The first argument is the file to clone the dustbin from.
  // If a file is specified, the dustbin won't get its default
  // settings, so you should not write a filename there, when
  // you are not absolutely sure that you set all necessary data.
  // Well in fact, the necessary data are only those of a normal
  // /std/container.
  // If you give 0 as argument, a /std/container will be cloned and the
  // default settings will be made. In addition you may change some of
  // the settings with the following mapping:
    ([P_SHORT:"an awful looking dustbin",
      P_LONG:"This dustbin is really dirty.\n",
      P_ADS:({"dirty","awful","looking"})
    ]));
  // You can do the same with SetShopkeeper and SetStore.

  SetShopkeeper(MONSTER("hartward"));
  SetBuyFactor(290);	// You have to pay 290% of the value of an item
  SetSecurity(1); // noone should enter the store

  // Settings Dynamic and MinCash are obsolete in THIS shop,
  // because this shop has money without end. But again it's just to
  // show you, how to handle it:
  SetDynamic(30);	// see below
  SetMinCash (30000);	// if we go below this point of money, add some
			// money depending on the dynamic-factor (s. a.)
			// In this case the money will be resetted (in the
			// reset of course, if it is below 30000 NFCU and
			// it will be restored to 30000*30/100 = 9000

  if (query_host_name() == "quest")
  // Only add this article, when Nightfall is running an the nova
    {
      AddArticle("/p/houses/common/obj/catalogue",REFRESH_REMOVE);
    }

  AddExit ("west", "./storage");
  AddExit ("south", "./vill_road2");
}
