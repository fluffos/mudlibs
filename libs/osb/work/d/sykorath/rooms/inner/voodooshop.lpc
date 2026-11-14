/*
 * the nice voodoo shop
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

// madmonks will pay 1/3 less then other for items
int ModifyPrice(object ob,int price,string verb)
{
  if (this_player()
      && this_player()->QueryGuild()=="madmonks"
      && verb=="buy")
    return price*2/3;
  return price;
}

// give the normal sign-description with an additional text
string detail_sign()
{
  return (::detail_sign())+
    "\nAt the bottom of the sign you read:\n"
    "           No credit.\n"
    " Madmonks will get a discount.\n";
}

// remove the not needed commands
int do_sell(string str) { return 0; }
int do_appraise(string str) { return 0; }
int do_identify(string str) { return 0; }

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The voodoo doll shop");
  SetIntLong(
    "You are standing in a special shop. You can buy some (ready to prick)\n"
    "dools and needles here and all items that you need to build your own\n"
    "voodoo doll.\n"
    "You can feel the dark magic all around you.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({580,540,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"shop"}),
    P_ADS:  ({"voodoo","doll","special"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"dolls","doll"}),
    P_ADS:  ({"voodoo"}),
    P_LONG: "You can buy some different voodoo dolls here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"needle","needles"}),
    P_LONG: "You can buy needles here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"magic"}),
    P_ADS:  ({"dark"}),
    P_LONG: "You can feel the dark magic coming from the voodoo "
            "shop.\n" ]) );

  SetBuyFactor(200);
  SetMinCash(30000);
  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);               // noone should enter the store
  SetSell(0);                   // disable sell command
  SetAppraise(0);               // disable appraise
  SetIdentify(0);               // disable identify

  /* shopkeeper */
  SetShopkeeper(NPC("vwoman"));

  /* Exits */
  AddDoor("south","./to_voodoo",
    ([ P_SHORT:    "a wooden door",
       P_LONG:     "A small wooden door\n",
       P_DOORCODE: "voodooshopdoor",
       P_ADS:      ({"wooden"}),
    ]) );

  /* articles */
  AddArticle(OBJ("vneedle"),REFRESH_REMOVE,5);
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,5);
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,1,
    ([ "VoodooName": "Kohl" ]) );
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,1,
    ([ "VoodooName": "Franzi" ]) );
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,1,
    ([ "VoodooName": "Blubber" ]) );

  Set(P_INT_WIZMSG,
    "%^RED%^add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

