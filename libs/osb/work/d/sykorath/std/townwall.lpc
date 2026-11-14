/* -------------------------------------------------------------------------
 * basic room for the osb domain
 * this room if for using inside the townwall only!
 * -------------------------------------------------------------------------
 * 15-Jan-98 [MagicTcs]  Creation
 * -------------------------------------------------------------------------
 * 15 jan 98 [MagicTcs]  Added NowayMsgs for being inside the townwall
 */

// TODO: add light/unlight torches (code is prepared, fill in the missing)
// TODO: replace torches (put torch into (empty) holder
// --> little quest to replace such a torch?

#include <properties.h>
#include <msgclass.h>
#include <moving.h>
#include <nightday.h>
#include <npc.h>
#include <sykorath.h>

inherit BASEROOM;

/*
 * torch handling
 */

//***********
// variables:
//***********
string vitem_holder;           // needed for changing the ads!
string vitem_torch;            // needed for torch handling

//*******************
// property handling:
//*******************
int QueryTorch() { return VQuery(vitem_torch,P_AMOUNT); }

// don't set only values of 0,1 or 2 !
int SetTorch(int t) { VSet(vitem_torch,P_AMOUNT,t); return QueryTorch(); }

//********************************
// look at holder(s) and torch(es)
//********************************
string look_holder() {
  switch (VQuery(vitem_torch,P_AMOUNT)) {
    case 2:
      return "There are two holder with two torches mounted.\n";
    case 1:
      return "There is an empty holder and a holder with a "
             "torch mounted.\n";
    default:
      return "There are two empty holders on the wall.\n";
  }
}

string look_torches() {
  switch(VQuery(vitem_torch,P_AMOUNT)) {
    case 2:
      return "Two torches are inside the holder.\n";
    case 1:
      return "One torch is still inside a holder.\n";
    default:
      return 0;
  }
}

// clone one torch and return the object
// function is needed, because we want to add the "empty" adjective to the
// holders! (else this function isn't really needed)
object clone_torch() {
  object obj;
  obj=clone_object("/obj/torch");
  VSet(vitem_holder,P_ADS,({"empty"}));
  return obj;
}

//********************
// light/unlight torch
//********************
/*
int light_torch(string str) {
  return 1;
}

int unlight_torch(string str) {

  return 1;
}
*/

//*******
// create
//*******
create() {
  ::create();
  SetIntLight(0);                  // two torches are not burning!

  /* special details */
  SetExtraEntry("torch", P_INT_LONG,#'look_holder);
  vitem_holder=AddVItem( ([
    P_IDS:  ({"holder","holders"}),
    P_NOGET: "The holders are mounted to the wall.\n",
    P_LONG: #'look_holder ]) );
  vitem_torch = AddVItem( ([
    P_IDS:  ({"torch","torches"}),
    PV_ITEM_LOCATION: #'clone_torch, // is get-able
    P_AMOUNT:2,                      // two torches are there
    P_LONG: #'look_torches ]));

  /* commands */
/*
  AddRoomCmd("light",#'light_torch);
  AddRoomCmd("unlight",#'unlight_torch);
*/

  SetNowayMsg("You bump against the townwall. Ouch.\n");
}

//*********************
// don't remove this!!!
//*********************
// needed for exit handling! (noway-msg)
init() {
  ::init();
}

//************************
// we need a special reset
//************************
reset() {
  if (VQuery(vitem_torch,P_AMOUNT) !=2 ) {
    show_room(TO,"An old gnome comes along and replaces the missing "
      "torches. Then he walks away.\n");
    VSet(vitem_holder,P_ADS,0);       // remove the ads
  }
  ::reset();
}

