// made by magictcs - 7 aug 97
// special entrance to the sea below the earth
// place the room somewhere in sykorath (in the city)!

// TODO: add more details and description
// TODO: place more exits to the normal city
// TODO: update coords
// TODO: make it climbable only if there is a rope connected (tied) to the
//       well

#include <properties.h>
#include <moving.h>
#include <sykorath.h>
#include <npc.h>
#include <rope.h>
#include <regions.h>
#include <coordinates.h>

inherit BASEROOM;

//*************************
// climb down into the well
//*************************
int climb(string str) {
  object ob;
  if (!str) { notify_fail("Climb where?\n"); return 0; }
  notify_fail("Climb down?\n");
  if (member(({"down","down the well","down into well"}),str)!=-1) {
    write("You use the handles to climb down.\n");
    // move each player into its own climb down room!
    // the climb down room is selfdestructing if the player leaves the room
    ob=clone_object(SYKORATH("sea/climbsea"));
    TP->move(ob,M_TELEPORT,({"climbs down the handles","xxx"}));
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("On an alley");
  SetIntLong(
    "A narrow alley. There is a well in the middle.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"alley","narrow alley"}),#'IntLong);
  AddDetail("middle","An old well stands in the middle.\n");
  AddVItem( ([
    P_IDS:  ({ "well" }),
    P_ADS:  ({ "old","dry","very old" }),
    P_LONG: "It is a very old well. You look down the well, but see only "
            "darkness. There is no water in it, but you see some iron "
            "handles.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "handle","handles" }),
    P_ADS:  ({ "iron","some" }),
    P_LONG: "The irons handles are rusty, but they look like that you can use "
            "them to climb down.\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({ "darkness" }),
    P_LONG: "It is very dark inside the well.\n"
    ]) );
  AddDetail("water","This well is dried out.\n");

  /* commands */
  AddRoomCmd("climb","climb");

  /* exits */
  AddExit();
}

