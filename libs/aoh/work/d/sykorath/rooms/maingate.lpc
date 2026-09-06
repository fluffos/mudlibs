// part of the inner town
// made by magictcs - 22 may 97

// and a pullchain which can be opened:
// pull pullchain when closed
// TODO: two guards?
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

#define BEFOREROOM         SYKORATH("beforegate")

inherit BASEROOM;

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
    return TP->move(SYKORATH("beforegate"),M_GO,"west");
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
      tell_room(TO,"The gate closes.\n");
      tell_room(BEFOREROOM,"The gate closes.\n");
      gate="closed";
    } else {
      tell_room(TO,"The gate opens.\n");
      tell_room(BEFOREROOM,"The gate opens.\n");
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

create() {
  ::create();
  gate="closed";
  SetIntShort("The inner town gate");
  SetIntLong(
    "You are standing in the townwall near a huge gate to the west. It is\n"
    "the exit from the inner city of town.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"town"}),
    "The townwall belongs to the town as each other place here.\n");
  AddDetail(({"city","inner city"}),
    "You are in the inner city. You can leave it by passing the huge gate\n"
    "to the west.\n");
  AddDetail("exit","The exit from the inner city is to the west.\n");
  AddDetail(({"townwall"}),
    "You are standing in it. It is a very old townwall. You can surround the\n"
    "town inside the townwall by going north or south.\n"
    "Two towers are standing north and south beside the gate.\n");
  AddDetail(({"north","south"}),"One tower is there.\n");
  AddDetail(({"towers","two towers"}),
    "Two of them are standing north and south beside the gate.\n");
  AddDetail("tower",
    "Which tower? The one to the north or the one to the south?\n");
  AddDetail(({"tower north","north tower"}),
    "You can enter it by going north.\n");
  AddDetail(({"tower south","south tower"}),
    "You can enter the tower by going south.\n");
  AddDetail(({"gate","huge gate","west"}),#'lookgate);
  AddDetail("pullchain","You can pull the pullchain!\n");
  /* items */
//  AddItem(NPC("gateguard"),REFRESH_REMOVE,2);

  /* command */
  AddRoomCmd("pull",#'pull);

  /* Exits */
  AddNowayMsg("west","You bump against the closed gate. Ouch, that hurts.\n");
  AddExit("east","./mainroadw");
  AddExit("west",#'go_west);
  AddExit("north","./towern");
  AddExit("south","./towers");
}

reset() {
  ::reset();
  gate="closed";
}

