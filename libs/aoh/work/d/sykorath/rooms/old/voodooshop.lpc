// part of the mainplaza of the town
// made by magictcs - 22 may 97
// a shop for voodoo dolls and needles

// TODO: update coords

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

create() {
  ::create();
  SetIntShort("The voodoo doll shop");
  SetIntLong(
    "You are standing in a special shop. You can buy some (ready to prick)\n"
    "dools and needles here and all items that you need to build your own\n"
    "voodoo doll.\n"
    "You can feel the dark magic all around you.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"voodoo doll shop","special shop","shop"}),#'IntLong);
  AddDetail(({"dolls","voodoo dolls","doll","voodoo doll"}),
    "You can buy some different voodoo dolls here.\n");
  AddDetail(({"needle","needles"}),
    "You can buy needles here.\n");
  AddDetail(({"magic","dark magic"}),
    "You can feel the dark magic coming from the voodoo shop.\n");

  SetIndoors(1);
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
  AddDoor("south","./mainroadn",
    ([ P_SHORT:    "a wooden door",
       P_LONG:     "A small wooden door\n",
       P_DOORCODE: "voodooshopdoor",
       P_ADS:      ({"wooden"}),
    ]) );

  /* articles */
  AddArticle(OBJ("vneedle"),REFRESH_REMOVE,5);
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,5);
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,1,
    ([ "VoodooName": "Cormallon" ]) );
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,1,
    ([ "VoodooName": "Franzi" ]) );
  AddArticle(OBJ("vdoll"),REFRESH_REMOVE,1,
    ([ "VoodooName": "Blubber" ]) );
}

