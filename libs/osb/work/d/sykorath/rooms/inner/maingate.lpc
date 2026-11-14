/*
 * main entrance to the inner city
 * pullchain which can be opened
 * pull pullchain when closed
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

// TODO: two guards?
// TODO: add rooms to the east

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

#define BEFOREROOM         OUTER("beforegate")

inherit TOWNWALL;

string gate;                            // open,closed

//******************
// property handling
//******************
string QueryGate() { return gate; }
string SetGate(string str) {
  if (str) { 
    switch (str) {
      case "open":   { gate=str;
                       tell_room(TO,"The gate opens.\n");
                       return gate; }
      case "closed": { gate=str;
                       tell_room(TO,"The gate closes.\n");
                       return gate; }
      default: return 0;
    }
  }
  return 0;
}

//***********
// leave town
//***********
int go_west() {
  if (gate=="open") {
    return TP->move(BEFOREROOM,M_GO,"west");
  }
  show(NAME+" tries to leave the inner town, but fails.\n");
  return ME_NO_MOVE;
}

//***************
// pull pullchain
//***************
// maybe open the exit ?
int pull(string str) {
  if (!str) { notify_fail("Pull what?\n"); return 0; }
  if (str=="pullchain") {
    write("You pull the pullchain.\n");
    show(NAME+" pulls the pullchain.\n");
    if (gate=="open") {
      show_room(TO,"The gate closes.\n");
      show_room(BEFOREROOM,"The gate closes.\n");
      gate="closed";
    } else {
      show_room(TO,"The gate opens.\n");
      show_room(BEFOREROOM,"The gate opens.\n");
      gate="open";
    }
    return 1;
  }
  notify_fail("Pull what?\n");
  return 0;
}

//****************
// detail handling
//****************
string lookgate() {
  return
  "There is a "+gate+" gate here. It is made of thick planks of oak wood.\n"
  "A pullchain can be seen on the left side.\n";
}

//*******
// create
//*******
create() {
  ::create();
  gate="closed";
  SetIntShort("The inner town gate");
  SetIntLong(
    "You are standing in the townwall near a huge gate to the west. It is "
    "the exit from the inner city of town.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({500,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddDetail("town",
    "The townwall belongs to the town as each other place here.\n");
  AddVItem( ([
    P_IDS:  ({"city"}),
    P_ADS:  ({"inner"}),
    P_LONG: "You are in the inner city. You can leave it by passing "
            "the huge gate to the west.\n" ]) );
  AddDetail("exit","The exit from the inner city is to the west.\n");
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"old","very"}),
    P_LONG: "You are standing in it. It is a very old townwall. You "
            "can surround the town inside the townwall by going north "
            "or south. Two towers are standing north and south beside "
            "the gate.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"north","south"}),
    P_LONG: "One tower is there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"towers"}),
    P_ADS:  ({"two"}),
    P_LONG: "Two of them are standing north and south beside the "
            "gate.\n" ]) );
  AddDetail("tower",
    "Which tower? The one to the north or the one to the south?\n");
  AddVItem( ([
    P_IDS: ({"tower north","north tower"}),
    P_LONG: "You can enter it by going north.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"tower south","south tower"}),
    P_LONG: "You can enter the tower by going south.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"gate"}),
    P_ADS:  ({"huge"}),
    P_LONG: #'lookgate ]) );
  AddDetail("west",#'lookgate);
  AddDetail("pullchain","You can pull the pullchain!\n");

  /* items */
//  AddItem(NPC("gateguard"),REFRESH_REMOVE,2);

  /* command */
  AddRoomCmd("pull",#'pull);

  /* Exits */
  AddNowayMsg("west","You bump against the closed gate. Ouch, that hurts.\n");
  AddExit("east","./mainplazaw");
  AddExit("west",#'go_west);
  AddExit("north",TOWNWALLI("towern"));
  AddExit("south",TOWNWALLI("towers"));

  Set(P_INT_WIZMSG,
    "%^RED%^add rooms to the east, add more details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

//**************
// special reset
//**************
reset() {
  ::reset();
  gate="closed";
}

