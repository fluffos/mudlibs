/* part of the mainplaza of the town
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

// adventureres will pay 1/3 less then other for items
// TODO: change it for soem special guilds!!!
int ModifyPrice(object ob,int price,string verb)
{
  if (TP && TP->QueryGuild()=="adventurer" && verb=="buy")
    return price*2/3;
  return price;
}

// Adventurers may get 2000 cc at maximum, others 1000
int GetMaxPrice()
{
  return 4500+500*((int)(TP && TP->QueryGuild()=="adventurer")+1);
}

// give the normal sign-description with an additional text
string detail_sign()
{
  return (::detail_sign())+
    "\nAt the bottom of the sign you read:\n"
    "           No credit.\n"
    " Adventurers will get a discount.\n";
}

create() {
  ::create();
  SetIntShort("The general shop");
  SetIntLong(
    "You are standing in the general shop. You can buy or sell things here.\n"
    "Often players come here to talk to each others.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({600,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"shop"}),
    P_ADS:  ({"general"}),
    P_LONG: #'IntLong ]) );

  /* shop specific */
  SetBuyFactor(200);
  SetMinCash(30000);
  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);       // noone should enter the store
  SetDynamic(30);       // see below
  SetMinCash (30000);   // if we go below this point of money, add some
                        // money depending on the dynamic-factor (s. a.)
                        // In this case the money will be resetted (in the
                        // reset of course, if it is below 30000 NFCU and
                        // it will be restored to 30000*30/100 = 9000

  /* shopkeeper */
  SetShopkeeper(NPC("mafiosi"));

  /* Exits */
  AddExit("north","./mainplazas");
  AddExit("east","./toilet");

  /* articles */
//  AddArticle("/obj/torch",REFRESH_REMOVE,5);
  AddArticle("/std/weapon",REFRESH_REMOVE,2);
  AddArticle("/std/armour",REFRESH_REMOVE,2);
  AddArticle("/std/armour",REFRESH_REMOVE,3,({
    ([ P_STANDARD: ({ AT_MAIL,1,PSIZE_GENERIC}) ]),
    ([ P_SHORT: "a mail",
       P_LONG: "This mail is made of old bamboo!\n",
       P_WEIGHT: 500,
       P_VALUE: 402,
       P_ADS: ({"bamboo","old"}),
       P_IDS: ({"mail"})]) }) );


  Set(P_INT_WIZMSG,
    "%^RED%^check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

