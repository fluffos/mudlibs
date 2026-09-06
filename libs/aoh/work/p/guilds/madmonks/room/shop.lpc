// storage for the Madmonks
// made by MagicTCS - 21 may 1997

#include <rooms.h>
#include <properties.h>
#include <moving.h>
#include "/p/guilds/madmonks/madmonks.h"

inherit "/std/shop";


void create(){
  ::create();
  SetIntShort("Dojo shop");
  SetIntLong(
    "You entered a huge chamber - the dojo shop.\n"
    "Here you can ask for new items or buy some useful stuff.\n"
    "Shelves filled with different items decorate two of the walls.\n"
    "The exit lies to the north.\n");

  AddDetail(({"chamber","huge chamber","dojo shop"}),#'IntLong);
  AddDetail(({"shelves","shelf"}),
    "There are many shelves made of oak wood. Items can be stored\n"
    "there. Some of the shelves are used.\n");
  AddDetail(({"oak","oak wood","wood"}),
    "The shelves are made of this wood.\n");
  AddDetail(({"item","items","different items"}),
    "Many items - but what else did you expect in a shop?\n");
  AddDetail(({"wall","walls","two walls"}),
    "Many shelves decorate two walls.\n");

  SetIndoors(1);
  SetShopkeeper(MONKNPC("yakuzo"));

  SetBuyFactor(200);
  SetMinCash(30000);
  SetSell(0);                   // forbid sell,appraise,identify
  SetAppraise(0);
  SetIdentify(0);

  AddExit("north",MONKROOM("madmonks"));

  AddArticle("/obj/torch", REFRESH_REMOVE);
//  AddArticle(OBJ("spack"), REFRESH_REMOVE, 5);   // shuriken package
//  AddArticle(OBJ(""), REFRESH_REMOVE, 5);
}

int do_sell(string str) { return 0; }
int do_appraise(string str) { return 0; }
int do_identify(string str) { return 0; }

//*******************************
// entering and leaving this room
//*******************************
// forbid entering for non HLP Madmonks
allow_enter(int method, mixed extra) {
  if (!interactive(PO)) return ME_OK;   // all non player (npc,items,...)
  if (IS_IMMORTAL(PO)) return ME_OK;     // wizzes allowed
  if (PO->QueryGuild()==GC_MADMONKS)
    return ME_OK;                       // madmonks allowed too 
  return ME_NO_ENTER;                   // forbid all others
}

