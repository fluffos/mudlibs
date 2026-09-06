// part of the town
// made by magictcs - 3 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//*************
// get ladder?!
//*************
int gettake(string str) {
  if(!str) return 0;
  if (present(str)) return 0;
  if (str=="ladder") {
    write("The ladder can't be taken. It is fixed to the ceiling and "
      "the ground.\n");
    return 1;
  }
  return 0;
}

//**************
// command climb
//**************
int climbup(string str) {
  notify_fail("Climb what?\n");
  if (!str) return 0;
  if (member(({"ladder","up","ladder up","up using the ladder"}),str)!=-1) {
    write("You climb the ladder up.\n");
    TP->move(SYKORATH("houseu2"),M_GO,"up");
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The second story");
  SetIntLong(
    "You are standing in the second story of a huge house.\n"
    "A ladder leads up and a stony staircase down.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"house","huge house"}),#'IntLong);
  AddDetail(({"second story","story"}),
    "This is the second story of the house.\n");
  AddDetail("up",
    "The ladder leads up to the top of the house. You can climb it up.\n");
  AddDetail("ceiling","You can climb the ladder up.\n");
  AddDetail("ground","A ladder is fixed on the ground.\n");
  AddDetail("ladder","You climb up using the ladder.\n");
  AddDetail(({"staircase","stony staircase"}),
    "It leads down to a lower story.\n");

  /* commands */
  AddRoomCmd("get","gettake");
  AddRoomCmd("take","gettake");
  AddRoomCmd("climb","climbup");

  /* exits */
  AddExit("down","./housee1");
}

