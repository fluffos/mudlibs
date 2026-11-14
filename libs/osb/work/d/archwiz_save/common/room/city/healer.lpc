#include <properties.h>
#include <moving.h>
#include <stdrooms.h>

inherit HEALER;

//**************
// sign handling
//**************
string readsign() {
  return "You read the wooden sign:\n"+QuerySignDesc();
}

create() {
  ::create();
  SetIntShort("The healer office");
  SetIntLong(
    "You are standing in the healer office. This healer accepts gold coins\n"
    "only.\n"
    "A wooden sign hangs on one wall.\n");

  /* healer stuff */
  AllowTreat();                                // treat wounds
  AllowPoison();                               // cure poison
  AllowVirus();                                // cure virus
  AllowCurse();                                // cure curse

  /* works like the shop */
//  SetHealer(NPC("healer"));

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
  AddExit( "west", "/d/archwiz/common/room/city/eastroad1" );
}

