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
  SetIntShort("On the orc street");
  SetIntLong(
    "This is part of the orc street leading to the slums where orcs live. "
    "A lot of dirt is lying on the ground. "
    "The orcish slums are to the south.\n"
    "A sign is erected here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({420,740,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetMap("outer");

  // details:
  AddVItem( ([
    P_IDS:  ({"street"}),
    P_ADS:  ({"orc"}),
    P_LONG: "You are standing on it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"dirt"}),
    P_LONG: "It's dirt, nothing less and nothing more.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"slum","slums"}),
    P_ADS:  ({"orcish"}),
    P_LONG: "The slums are further to the south. Be careful when entering!\n"
    ]) );
  AddVItem( ([
    P_IDS:  ({"sign"}),
    P_ADS:  ({"wooden"}),
    P_LONG: "A wooden sign is erected here. Some words are written to the "
            "sign. You can read it.\n",
    P_READ_MSG: "You read:\n"
            "   --- OR   ---  AR A ---\n"
            "  Stay ou , or you wi l be killed!\n"
    ]) );

  // Exits
  AddExit("northwest","./orcstreet6");
  AddExit("south","./orc_slum");               // not done yet
}

