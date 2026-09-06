// part of the outer city of the town
// made by magictcs - 26 may 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

#define GATEROOM      SYKORATH("maingate")

inherit BASEROOM;

//*******
// moving
//*******
int goeast() {
  // check the gate if it is open!
  if (call_other(GATEROOM,"QueryGate") == "open") {
    tell_room(TO,"The gate closes behind "+NAME+".\n");
    call_other(GATEROOM,"SetGate","closed");
    return TP->move(SYKORATH("maingate"),M_GO,"through the gate");
  }
  return ME_NO_MOVE;       // use Nowaymsg for "east" !
}

//**************
// gate handling
//**************
int pull(string str) {
  if (!str) { notify_fail("Pull what?\n"); return 0; }
  if (member(({"rope","the rope"}),str) != -1) {
    write("You pull the rope.\n"
      "Doing doing.\n");
    show(NAME+" pulls the rope.\n");
    call_out("view_man",2);
    return 1;
  }
  notify_fail("Pull what?\n");
  return 0;
}

void view_man() {
  string gate;
  gate=call_other(GATEROOM,"QueryGate");
  if (gate=="closed") {
    tell_room(TO,
    "An bent old man appears and asks about your business:\n"
    "  'Oh you want in? Just a moment please.\n");
    call_out("opengate",2);
  } else {                   // gate is open!
    tell_room(TO,
    "Nothing happens.\n");
  }
}

void opengate() {
  call_other(GATEROOM,"SetGate","open");
  tell_room(TO,"You hear a loud rumble. The gate opens.\n");
}

//*********
// get take
//*********
// players want get/take all (s)he sees :=)
int gettake(string str) {
  if (!str) return 0;
  if (present(str)) return 0;              // for dropped items!!
  if (member(({"rope","rope from gate","rope from bell"}),norm_id(str))!=-1) {
    write("You can't get the rope. It is stuck to the bell.\n");
    return 1;
  }
  if (member(({"bell","small bell","gold bell","small golden bell",
    "golden bell"}),str)!=-1) {
    write("The bell is to high above you to reach to it.\n");
    return 1;
  }
  return 0;
}

//****************
// detail handling
//****************
string lookgate() {
  return
  "It's a huge gate made of oak wood and it is "+
    call_other(GATEROOM,"QueryGate")+".\n";
}

create() {
  ::create();
  SetIntShort("Before a huge gate");
  SetIntLong(
    "You are standing right before a huge gate to the east. It is the gate\n"
    "to the inner city of the town. A rope hangs on the left side of the gate.\n"
    "Two huge tower frame the gate on either side.\n");
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"gate","huge gate"}),#'lookgate);
  AddDetail(({"two towers","two huge towers"}),
    "Yes - two towers, one to the left, one to the right.\n");
  AddDetail(({"towers","watchtowers"}),
    "They have to be the watchtowers of the inner city.\n");
  AddDetail(({"left tower","tower left","tower to the left"}),
    "It is one of the watchtowers of the inner city. It is used to check the\n"
    "north part of the town.\n");
  AddDetail(({"right tower","tower right","tower to the right"}),
    "It is one of the watchtowers of the inner city. It is used to check the\n"
    "south part of the town.\n");
  AddDetail(({"city","inner city","outer city"}),
    "You are standing in the outer city. Behind the gate lies well the\n"
    "protected inner city.\n");
  AddDetail("rope",
    "The rope is connected to a small bell above you.\n");
  AddDetail(({"bell","small bell","gold bell","small golden bell",
    "golden bell"}),
    "The bell is made of pure gold. The bell will give a clear sound if you\n"
    "pull the rope.\n");
  AddDetail("town",#'IntLong);

  /* commands */
  AddRoomCmd("pull",#'pull);
  AddRoomCmd("get",#'gettake);
  AddRoomCmd("take",#'gettake);

  /* exits */
  AddNowayMsg("east","You bump against the closed gate. Ouch, that hurts.\n");
  AddExit("east",#'goeast);
  AddExit("west","./roadw3");
}

