// part of the town
// made by magictcs - 23 jul 97

// TODO: add more details (and something special)
// TODO: update coords

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On the oakstreet");
  SetIntLong(
    "You are walking on the oakstreet. The street is named after an oak to\n"
    "standing more to the northeast. North stands a huge watchtower.\n"
    "Southeast is a small shop. A sign hangs over the entry.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"street","oakstreet","oak street"}),#'IntLong);
  AddDetail(({"oak","oak tree","huge oak","huge tree"}),
    "You can't see the oak from here. You are too far away.\n");
  AddDetail(({"watchtower","huge watchtower"}),
    "It has to be very huge if you can see it from here!.\n");
  AddDetail("north","A huge watchtower stands there.\n");
  AddDetail("shop","");
  AddDetail(({"sign","sign over entry","sign over the entry"}),
    "The sign belongs to the shop to the southeast. Some words are painted\n"
    "to the shop.\n");
  AddReadMsg(({"sign","sign over entry","sign over the entry","words",
    "some words"}),
    "You read the sign:\n"
    "The candy shop.\n");
  AddDetail(({"word","words","some words","word of sign","words of sign",
    "some words of sign"}),
    "You can read the words.\n");
  AddDetail("entry","It is the entry of the shop.\n");

  /* exits */
  AddExit("north","./oakstreets1");
  AddExit("southeast","./candyshop");
  AddExit("east","./oakstreets3");
}

