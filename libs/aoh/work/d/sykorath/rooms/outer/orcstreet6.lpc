//
// part of south street
// initial version - magictcs - 13 sept 98
//

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

create() {
  ::create();
  SetIntShort("On a small path");
  SetIntLong(
    "This is part of the orc street leading to the slums where orcs live. "
    "A lot of dirt is lying on the ground. "
    "To the southwest is a house. A sign is nailed above the smashed "
    "entrance door.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({400,720,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetMap("outer");

  // details:
  AddVItem( ([
    P_IDS:  ({"street"}),
    P_ADS:  ({"orc"}),
    P_LONG: "You are on this street leading into the orcish area.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"slum","slums"}),
    P_ADS:  ({"orc","orcish"}),
    P_LONG: "The slums are further to the southeast. Be careful, orcs are "
            "seldom friendly.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"dirt"}),
    P_LONG: "As you touch the dirt you get dirty fingers....\n" ]) );
  AddVItem( ([
    P_IDS:  ({"ground"}),
    P_ADS:  ({"dirty"}),
    P_LONG: "The ground is really dirty. Seems noone is cleaning the "
            "street.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"sign"}),
    P_LONG: "On the sign are painted a word in huge letters. You can "
            "read it.\n",
    P_READ_MSG: "You read the sign:\n"
            " .oO  Fluffies Pipeshop  Oo.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"entrance","door"}),
    P_ADS:  ({"entrance","smashed"}),
    P_LONG: "This smashed door leads into the house.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"house"}),
    P_LONG: "This house is of normal height. Looks like the house of a "
            "human.\n" ]) );


  // Exits
  AddExit("north","./orcstreet5");
  AddExit("southeast","./orcstreet7");
  AddExit("southwest","./pipeshop");
}

