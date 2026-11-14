// part of the town
// made by magictcs - 20 jun 97
// TODO: add exit of healer
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/room/healer";

//**************
// sign handling
//**************
string readsign() {
  return "You read the wooden sign:\n"+QuerySignDesc();
}

//*******
// healer
//*******
//string Name(mixed cap) {
//  return "Ganimhar";                          // ever capitalzied!
//}

create() {
  ::create();
  SetIntShort("The healer office");
  SetIntLong(
    "You are standing in the healer office. This healer accepts gold coins\n"
    "only.\n"
    "A wooden sign hangs on one wall.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  CloseNight();                                // closed at night!
  AddValuta("gold");                           // only gold coins
  // TODO: the healer should take gold coins ONLY (no 'really')

  /* healer stuff */
  AllowTreat();                                // treat wounds
  AllowPoison();                               // cure poison
  AllowVirus();                                // cure virus
  AllowCurse();                                // cure curse

  SetHealer(NPC("healer"));                    // the healer itself

  /* details */
  RemoveDetail(({"hut","entrance","healer","old man","man","sign"}));
  AddDetail(({"office","healer office"}),#'IntLong);
  AddDetail("walls","The walls look equal except one wall.\n");
  AddDetail(({"wall","one wall"}),
    "On one wall hangs a wooden sign.\n");
  AddDetail(({"sign","wooden sign"}),
    "It is a wooden sign. Some words are carved into it.\n");
  AddDetail(({"words on sign","words on wooden sign","some words on sign",
    "some words on wooden sign","words of sign","words of wooden sign",
    "some words of sign","some words of wooden sign","words"}),
    "You can read the sign.\n");
  AddReadMsg(({"sign","wooden sign","words"}),#'readsign);

  /* exits */
  AddExit();
}

