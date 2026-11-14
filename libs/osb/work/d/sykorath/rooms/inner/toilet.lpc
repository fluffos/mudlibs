/* part of the mainplaza of the town
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <search.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

// special functions for the hole
void plop() {
  tell_room(TO,
    "You hear a loud plop as the shit hits the ground of the hole.\n");
}

void  blubb() {
  tell_room(TO,
    "You hear a loud blubb as the piss hits the ground of the hole.\n");
}

void platsch() {
  tell_room(TO,
    "You hear a loud platsch as something hits the ground of the hole.\n");
}

//*****
// shit
//*****
int shit(string str) {
  if (str) {
    if (member(({"hole","into hole","into the hole"}),str)==-1) {
      notify_fail("Shit where?\n"); return 0;
    }
  }
  write("You unwear your clothes and shit into the hole.\n");
  show(NAME+" shits into the hole.\n");
  call_out("plop",2);
  return 1;
}

//*****
// piss
//*****
int piss(string str) {
  if (str) {
    if (member(({"hole","into hole","into the hole"}),str)==-1) {
      notify_fail("Piss where?\n"); return 0;
    }
  }
  write("You unwear your clothes and piss into the hole.\n");
  show(NAME+" pisses into the hole.\n");
  call_out("blubb",2);
  return 1;
}

//*********************
// special drop command
//*********************
// drop xxx into (the) (little) hole
int dodrop (string str) {
  string *exp;
  object what;
  mixed nodrop;
  if (!str) return 0;
  // split the input string at position "into"
  // the spaces around into are not a bug, they are needed!!! -> " into "
  exp=explode(str," into ");              // search for 'into' or 'to'
  if (sizeof(exp)!=2) {
    exp=explode(str," to ");
    if (sizeof(exp)!=2) return 0;
  }
  // check for the what:
  what=TP->Search(exp[0],SEARCH_INV|SM_OBJECT);
  if (!what) return 0;
  // maybe replace the member by strstr(exp[1],"hole")??
  if (member(({"hole","little hole","the hole","the little hole"}),
    exp[1])==-1) return 0;
  // maybe move the item simple with a normal M_GO and check the return value?
  nodrop=what->QueryNoDrop();
  if (nodrop==1) {
    write(CAP(add_a(what->QueryShort()))+" can't be dropped.\n");
    return 1;
  }
  if (stringp(nodrop)) {
    write(nodrop);
    return 1;
  }
  if (nodrop) return 0;             // anything else
  write("You drop "+add_a(what->QueryShort())+" into the hole.\n");
  show(NAME+" drops "+add_a(what->QueryShort())+" into the hole.\n");
  call_out("platsch",2);
  what->remove();
  return 1;
}

//***********
// enter hole
//***********
int enter(string str) {
  if (!str) return 0;
  // add more checks to the string:
  if (str=="hole" || str=="little hole") {
    write("You try to enter the hole, but it is too small for you.\n");
    show(NAME+" tries to enter the hole.\n");
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("In a toilet");
  SetIntLong(
    "You are in a toilet with a little hole in the ground.\n");
  SetIntSmell("A very bad smell enters your nose. Uhhh that stinks.\n");

  SetIndoors(1);
  SetCoordinates( ({ ({620,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddDetail(({"toilet"}),#'IntLong);
  AddDetail(({"ground"}),"A little hole is there.\n");
  AddVItem( ([
    P_IDS:  ({"hole"}),
    P_ADS:  ({"little"}),
    P_SMELL: "The foul stench comes from the hole.\n",
    P_LONG: "The inhabitants of this city come here to shit and piss "
            "into this hole.\n" ]) );

  /* commands */
  AddRoomCmd("shit",#'shit);
  AddRoomCmd("piss",#'piss);
  AddRoomCmd("drop",#'dodrop);
  AddRoomCmd("enter",#'enter);

  /* exits */
  AddExit("west","./mainshop");

  Set(P_INT_WIZMSG,
    "%^RED%^check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

// all items (non livings) dropped into the hole will vanish
void remove_item(object ob) {
  tell_room(TO,"As you drop "+ob->QueryShort()+
    " it falls through the hole.\n");
  call_out("platsch",2);
  ob->remove();
}

void notify_enter(object oldenv,int method,mixed extra) {
  ::notify_enter(oldenv,method,extra);
  if (interactive(PO)) return;         // no message for players
  if (PO->id("hole")) return;
  if (PO->QueryIsLiving()) {
    tell_room(TO,PO->QueryShort()+
      " is too big to fall though the hole. What for a luck.\n");
  } else {
    call_out("remove_item",1,PO);
  }
}
