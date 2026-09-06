// part of the town
// made by magictcs - 19 jun 97
// TODO: add views to the city
// TODO: add something special (maybe a mini quest?)
// TODO: add a rope to the clouds (as fast transport system)
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//****************
// detail handling
//****************
// use day/night server AND a random(mist and fog)
string lookeast() {
  return "";
}
string looknorth() {
  return "";
}
string lookwest() {
  return "";
}
string looksouth() {
  return "";
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The platform of the watchtower");
  SetIntLong(
    "You have reached the platform of the huge watchtower.\n"
    "There is a wonderful view over the whole city.\n"
    "The ground contains a trapdoor.\n");
  SetIndoors(0);             // the platform is outside!
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"watchtower","huge watchtower"}),#'IntLong);
  AddDetail(({"tower","hugest tower"}),
    "This is the hugest tower of this city. You will have a great view over\n"
    "the city if you are standing on the platform of this tower.\n");
  AddDetail("platform","You have reached the highest story.\n");
  AddDetail("highest story","Yes there is no way further up.\n");
  AddDetail("story",
    "You are standing on the highest story - on the platform.\n");
  AddDetail("ground","There is a trapdoor.\n");
  AddDetail("city",
    "In which direction do you want to look? (north,east,south,west)\n");
  AddDetail("east",#'lookeast);
  AddDetail("north",#'looknorth);
  AddDetail("south",#'looksouth);
  AddDetail("west",#'lookwest);
  AddDetail(({"view","wonderful view"}),
    "You can look at east, south, west and north.\n");

  /* exits */
  AddDoor("down","./watchtower6",
    ([
    P_SHORT:      "trapdoor",
    P_LONG:       "A trapdoor built into the ground.\n",
    P_IDS:        ({"door","trapdoor"}),
    P_LOCKSTATE:  LOCK_CLOSED,
    P_DOORCODE:   "watchtowerkey"
    ]) );
}

