// part of the city
// made by magictcs - 13 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//****************************************
// close the bridge (called from westgate)
//****************************************
int CloseBridge() {
  object *objs;
  int i;
  objs=all_inventory();         // find all objects here
  tell_room(TO,
    "Uhh what's this? The drawbridge moves sligthly to the east.\n"
    "Seems like it will be closed.\n"
    "You roll to the east.\n");
  filter_objects(objs,"move",SYKORATH("westgate"),M_TELEPORT,
    ({"roll out east","rolls in from west"}));
}

//*********************
// jump from the bridge
//*********************
int jump(string str) {
  if (!str) return 0;
  if (str!="down") return 0;
  write("You jump down from the bridge - huiiiii.\n");
  TP->move(SYKORATH("trench"),M_GO,"jumps from the drawbridge");
  return ME_OK;
}

//**********************
// fall down from bridge
//**********************
int falldown() {
  write("You fall down from the bridge.\n");
  TP->move(SYKORATH("trench"),M_GO,"falls down from the drawbridge");
  return ME_OK;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("On a drawbrdige");
  SetIntLong(
    "You are standing on a drawbridge. If you look down you see a trench.\n"
    "To the east is the westgate of Sykorath. The path west leads directly\n"
    "to Silvere.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail("drawbridge",#'IntLong);
  AddDetail(({"sykorath","Sykorath"}),
    "It is the city to the east.\n");
  AddDetail(({"path","path west","west"}),
    "You can go to Silvere there.\n");
  AddDetail("east","You found Sykorath there.\n");
  AddDetail("trench",
    "The trench divides the area into the town and the forest. The trench\n"
    "looks wet, Better not to jump down!\n");
  AddDetail("down","It is not recommended to jump down into the trench.\n");

  /* commands */
  AddRoomCmd("jump",#'jump);

  /* exits */
  AddExit("east","./westgate");
  AddExit("west","./silpath1");
  AddExit("north",#'falldown);
  HideExit("north",1);
  AddExit("south",#'falldown);
  HideExit("south",1);
}

