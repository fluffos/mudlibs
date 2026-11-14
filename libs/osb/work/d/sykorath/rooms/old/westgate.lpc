// part of the city
// made by magictcs - 9 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

string bridge;

//******************
// property handling
//******************
string QueryBridge() { return bridge; }
string SetBridge(string b) { bridge=b; return bridge; }

//*************
// enter bridge
//*************
int enterbridge() {
  if (bridge=="open") {
    write("You enter the drawbridge.\n");
    TP->move(SYKORATH("drawbridge"),M_GO,"west");
    return ME_OK;
  }
  return 0;
}

//***********
// move lever
//***********
void openbridge() {
  if (bridge=="open")
    tell_room(TO,"The drawbridge opens.\n");
  else tell_room(TO,"The drawbridge closes.\n");
}

int movelever(string str) {
  notify_fail("Move what?\n");
  if (!str) return 0;
  if (str=="lever") {
    if (bridge=="open") {
      write("You move the lever into the lower position.\n");
      bridge="closed";
      call_other(SYKORATH("drawbridge"),"CloseBridge");
    } else {
      write("You move the lever into the upper position.\n");
      bridge="open";
    }
    show(NAME+" operates with the lever.\n");
    call_out("openbridge",1);
    return 1;
  }
  return 0;
}

//***************
// detailhandling
//***************
string lookdrawbridge() {
  return
  "It is huge drawbridge made of hard wood. Actually it is "+bridge+".\n"
  "Near the drawbridge is a lever.\n";
}

string looklever() {
  string ret;
  ret="A moveable lever. ";
  if (bridge=="open") ret+="The lever is moved into the upper position.\n";
  else ret+="The lever is in the lower position.\n";
  return ret;
}

//*******
// create
//*******
create() {
  ::create();
  bridge="closed";
  SetIntShort("The west gate.\n");
  SetIntLong(
    "You are standing near the west gate of the outer city. The outer city\n"
    "extends to the east.\n"
    "A huge drawbridge blocks the way west.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"gate","west gate"}),#'IntLong);
  AddDetail(({"city","outer city"}),
    "The outer city is more to the east.\n");
  AddDetail(({"drawbridge","huge drawbridge"}),#'lookdrawbridge);
  AddDetail("lever",#'looklever);

  /* commands */
  AddRoomCmd("move",#'movelever);

  /* exits */
  AddNowayMsg("west",
    "You bump against the closed drawbridge. Ouch, that hurts.\n");
  AddExit("west",#'enterbridge);
  AddExit("east","./roadw1");
}

reset() {
  ::reset();
  if (bridge=="open") {
    tell_room(TO,"The drawbridge closes.\n");
    bridge="closed";
  }
}

