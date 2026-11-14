// part of the town
// made by magictcs - 19 jun 97

// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("The 6th story of the watchtower");
  SetIntLong(
    "This is the 6th story of the huge watchtower.\n"
    "A stony staircase leads down.\n"
    "You hear some rumble from above.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  SetIntNoise("You hear steps coming from above.\n");
  AddNoise(({"above","rumble"}),
    "You hear steps coming from above.\n");
  AddDetail(({"watchtower","huge watchtower"}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail(({"above","ceiling"}),
    "In the ceiling is a trapdoor.\n");
  AddDetail(({"staircase","stony staircase"}),
    "The staircase is carved into the stone of this tower. It leads down\n"
    "to a lower story.\n");

  /* exits */
  AddDoor("up","./watchtower7",
    ([
    P_SHORT:      "trapdoor",
    P_LONG:       "A trapdoor built into the ceiling.\n",
    P_IDS:        ({"door","trapdoor"}),
    P_LOCKSTATE:  LOCK_CLOSED,
    P_DOORCODE:   "watchtowerkey"
    ]) );
  HideDoor("up",HIDE_ALWAYS);          // or HIDE_CLOSED,HIDE_OPEN ?
  AddExit("down","./watchtower5");
}

