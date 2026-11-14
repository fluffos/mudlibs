// made by magictcs - 31 jul 97
// place the room somewhere below the earth?! (it is a cellar!)

// TODO: add some more different wines :)
// TODO: add more details :)
// TODO: update the press function and finish the fill function
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <sykorath.h>
#include <npc.h>
#include <drink.h>
#include <regions.h>
#include <coordinates.h>

inherit "/std/shop";

//****************************
// press grapes with winepress
//****************************
int press(string str) {
  string *tmp,normed;
  object grape;
  if (!str) { notify_fail("Press what with what?\n"); return 0; }
  normed=norm_id(str);
  tmp=explode(normed," with ");       // search " with " :)
  if (sizeof(tmp)!=2) {
    if (strstr(normed,"grape")!=-1) {
      notify_fail("Press what with what?\n",NOTIFY_NOT_VALID); return 0;
    }
    notify_fail("Press what with what?\n"); return 0;
  }
  // set notify_fail for all next checks as global
  notify_fail("Press what with what?\n",NOTIFY_NOT_VALID);
  grape=TP->Search(tmp[0],SEARCH_INV|SM_OBJECT);
  if (!grape) return 0;
  if (!(grape->id("grape"))) {
    notify_fail("You can press only grapes with the winepress.\n",
        NOTIFY_NOT_VALID); return 0;
  }
  if (member(({"winepress","press","the winepress","the press"}),tmp[1])==-1)
    return 0;
  grape->remove();              // remove the pressed out grapes
  write("You put some grapes into the winepress and turn the wheel of it."
    "You see some juice coming out of the press running into a small "
    "bottle.\n");
// TODO: update the drink here: --> should be grape juice!!!
  grape=clone_object("/std/drink");          // clone grape juice
  if (grape) TP->Take(grape,PUTGET_FULL);
  return 1;
}

//************************************
// fill (wine) juice into (empty) cask
//************************************
// TODO: code the fill function
// and give some QP to a player?
int fill(string str) {
  if (!str) { notify_fail("Fill what into where?\n"); return 0; }
  return 0;
}

//*****************
// enter empty cask
//*****************
int enter(string str) {
  if (!str) return 0;       // notify_fail is handled by global commands
  if (member(({"cask","open cask","empty cask","open and empty cask",
    "empty and open cask","open empty cask","empty open cask"}),
    norm_id(str))!=-1) {
    write("You enter the open and empty cask.\n");
// TODO: update the exit!
    TP->move(SYKORATH("winecask"),M_GO,"enters the cask");
    return 1;
  }
  return 0;
}

//**************
// check if wine
//**************
int CheckTrade(object obj) {
  if (obj->id("wine")) return 1;
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The winery");
  SetIntLong(
    "This is the winery of Sykorath. It is a huge cellar with different "
    "casks standing around. To the west you see many shelves with bottles "
    "in it. In the middle of the room stands a winepress.\n"
    "A counter for selling some of the wines is placed east.\n"
    "You can buy different types of wines here.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"winery"}),#'IntLong);
  AddDetail("west",
    "Some shelves with bottles filled with old wines are standing there.\n");
  AddDetail("east","The counter stands there.\n");
  // counter is handled by shop!
  AddDetail(({"cellar","huge cellar"}),
    "It is a huge cellar, a little bit wet, but filled with some nice "
    "equipment.\n");
  AddVItem( ([
    P_IDS:  ({ "equipment" }),
    P_ADS:  ({ "nice" }),
    P_LONG: "You see shelves, a winepress, some casks and a counter here.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "oldest shelf","oldest shelves" }),
    P_LONG: "The oldest shelves contains the best (the oldest) wine.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "shelf","shelves" }),
    P_ADS:  ({ "many","some" }),
    P_LONG: "To the west stands many shelves filled with bottles of wine. "
            "The shelves are made of oak wood. Some of them are very old. "
            "The oldest shelves contains the oldest wine.\n",
    ]) );
  AddVItem( ([
    P_IDS:  ({ "bottle","bottles","bottles of wine","wine","wines" }),
    P_ADS:  ({ "some","many" }),
    P_LONG: "There are some bottles of wine in the shelves. Some of them are "
            "buyable in this winery.\n"
    ]) );
  // maybe add a detail for the press - a wheel to turn ?
  AddVItem( ([
    P_IDS:  ({ "winepress","press" }),
    P_ADS:  ({ "wine","large" }),
    P_LONG: "It is a large winepress, made out of wood. It looks very old "
            "and used since centuries. Maybe you can press some bunches of "
            "grapes here?\n"
    ]) );
/*  AddVItem( ([
    P_IDS:  ({ "cask","casks" }),
    P_ADS:  ({ "oak","some","different" }),
    P_LONG: "The casks are made of oak. Most of them are filles with the "
            "white or red grape juice, but some are empty. You can fill them "
            "with your own juice, if you have some.\n"
            "One cask is emty and open.\n"
    ]) );
*/
  AddVItem( ([
    // don't split the ID here !! (--> it will be override the normal cask <--)
    P_IDS:  ({ "cask","open cask","empty cask","open and empty cask",
               "empty and open cask","open empty cask","empty open cask" }),
    P_ADS:  ({ "empty","open" }),
    P_LONG: "This cask is made of oak. It is empty, but sometimes it will be "
            "filled with fine wine. There is a small hole in front of the "
            "cask. You can enter the cask there.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "cask","casks" }),
    P_ADS:  ({ "oak","some","different" }),
    P_LONG: "The casks are made of oak. Most of them are filles with the "
            "white or red grape juice, but some are empty. You can fill them "
            "with your own juice, if you have some.\n"
            "One cask is emty and open.\n"
    ]) );

  /* special commands */
  AddRoomCmd("press","press");            // press grapes with winepress
  AddRoomCmd("fill","fill");              // fill juice into (empty) cask
  AddRoomCmd("enter","enter");            // enter empty cask

  /* shop specific */
  SetMinCash(6000);
  SetSell(0);           // no sell here
  SetAppraise(0);       // no appraise
  SetIdentify(0);       // no identify
  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);       // noone should enter the store
  RemoveDustbin();      // no dustbin in a winery!

  RemoveExit("store");  // hmm bad programmed mudlib :(
                        // RemoveStore removes the store with its content :(
                        // so better remove only the exit to the shop!

  /* shopkeeper */
  SetShopkeeper(0,([
    P_NAME:  "Barny",
    P_SHORT: "Barny the master of the old wines",
    P_LONG:  "It is a huge old man. He works in this winery for a long "
             "time. Sometimes he goes to the casks and checks the wine "
             "in it. But sometimes he sells some of his wines to guests.\n",
    P_CHAT_CHANCE: 6,
    P_CHATS: ({ "Barny works with a cask.\n",
                "Barny looks at some new bunch of grapes.\n",
                "Barny checks some wines.\n",
                "Barny works with a winepress.\n",
                "Barny tastes some wine.\n",
                "Barny fills some wine into wine-bottles and put them into "
                     "the store.\n",
                "A slave enters the winery, put some grapes into the "
                   "winepress and leaves the winery again.\n" })
  ]));

  /* Exits */
// TODO: update the exits
  AddExit();

  /* articles */
/*  std/drink is not working correctly !!!! :(
--> disabled until sonic finished the drink
  AddArticle("/std/drink",REFRESH_REMOVE,2,([
    P_SHORT: "AAAAA",
    P_LONG:  "BBBBB",
    P_BOTTLE_SHORT: "CCCCC",
    P_BOTTLE_LONG:  "DDDDD",
    P_DRINK_SHORT : "a bottle filled with red wine",
    P_DRINK_LONG  : "A bottle filled with red wine",
    P_IDS: ({ "wine" })
    ]) );
*/
}

// overload the function:
// otherwise they are not appear on the sign, but they are still working
// but gives an ugly output
int do_sell(string str)     { return 0; }
int do_appraise(string str) { return 0; }
int do_toss(string str)     { return 0; }
int do_identify(string str) { return 0; }
