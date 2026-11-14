//
// shoemaker
// made by Magictcs
// sells only shoes and boots
//
// initial version - 31 Aug 98

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/std/shop";

// remove the not needed commands
// shop will not buy,appraise or identify boots!
int do_sell(string str) { return 0; }
int do_appraise(string str) { return 0; }
int do_identify(string str) { return 0; }

// check if the trading object is of type boots/shoes
int CheckTrade(object ob) {
  if (ob->id("boots")) return 1;
  if (ob->id("boot"))  return 1;
  if (ob->id("shoes")) return 1;
  return 0;                          // discard all others
}

create() {
  ::create();
  SetIntShort("Shoemaker");
  SetIntLong(
    "This is the workroom of the best shoemaker in sykorath. Finest "
    "leather boots are available here. "
    "To the west you see a counter where Karlos is selling his work. South "
    "is a workbench. A lot of different tools are lying at the workbench."
    "\n"
  );

  SetIndoors(1);
  SetCoordinates( ({ ({40,68,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("outer");

  AddValuta("platinum");
  AddValuta("gold");
  AddValuta("silver");
  AddValuta("copper");
  SetSecurity(1);               // noone should enter the store
  SetSell(0);                   // disable sell command
  SetAppraise(0);               // disable appraise
  SetIdentify(0);               // disable identify
  RemoveDustbin();              // no dustbin in shoemaker shop

  /* shopkeeper */
  SetShopkeeper(NPC("karlos"));

  // details:
  // workroom,leather boots,counter,workbench,different tool,

  AddVItem( ([
    P_IDS:  ({""}),
    P_ADS:  ({""}),
    P_LONG: ""]) );


  // Exits:
  AddDoor("northwest","./orcstreet3",
    ([ P_SHORT:    "a wooden door",
       P_LONG:     "A small wooden door\n",
       P_DOORCODE: "syko_shoemakerdoor",
       P_ADS:      ({"wooden","small"}),
    ]) );
  AddDoor("south","./shoemaker_nailed_shut",
    ([ P_SHORT:    "a oak door",
       P_LONG:     "A oak wooden door. It is nailed shut. Noone is able "
                   "to open it.\n",
       P_DOORCODE: "syko_shoemakerdoor_nailed",
       P_CHECKDOOR: DACT_CHECK,             // needed to use CheckAction
       P_CHECKOBJ:  TO,                     // needed to use CheckAction
       P_ADS:      ({"oak"}),
    ]) );
  HideExit("store",HIDE_ALWAYS);

  AddArticle("/std/armour",REFRESH_REMOVE,2, ([
    P_SHORT:      "leather boots",
    P_LONG:       "These are leather boots. They are good work of Karlos, "
                  "the best shoemaker of Sykorath.\n",
    P_IDS:        ({"boots"}),
    P_ADS:        ({"leather"}),
    P_AC:         1,
    P_ARMOUR_TYPE:AT_BOOTS,
    P_WEIGHT:     800,
    P_VALUE:      300
    ]) );
  AddArticle("/std/armour",REFRESH_REMOVE,2, ([
    P_SHORT:      "combat boots",
    P_LONG:       "Combat boots are made to be worn - yes - on your feet. "
                  "They are good work of Karlos, the best shoemaker of "
                  "Sykorath.\n",
    P_IDS:        ({"boots"}),
    P_ADS:        ({"combat"}),
    P_AC:         1,
    P_ARMOUR_TYPE:AT_BOOTS,
    P_WEIGHT:     600,
    P_VALUE:      320
    ]) );
  AddArticle("/std/armour",REFRESH_REMOVE,3, ([
    P_SHORT:      "cowhide boots",
    P_LONG:       "These are boots made of thick cowhide. "
                  "You must be able to walk a long time in this boots. "
                  "They are good work of Karlos, "
                  "the best shoemaker of Sykorath.\n",
    P_IDS:        ({"boots"}),
    P_ADS:        ({"cowhide","thick"}),
    P_AC:         1,
    P_ARMOUR_TYPE:AT_BOOTS,
    P_WEIGHT:     700,
    P_VALUE:      200
    ]) );

}

// block commands for the door
int CheckAction (string action, string verb, string arg, int method) {
  switch (action) {
    case "lock":   
           notify_fail("The door is nailed shut.\n");
           return 0;           // no locking of this door allowed
    case "door":
         if (verb=="open") {
             notify_fail("The door is nailed shut.\n",NOTIFY_NOT_VALID);
             return 0;                 // door cannot be opened!
         }
    default: break;
  }
  return ::CheckAction(action,verb,arg,method);
}

