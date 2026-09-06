/* part of the mainplaza of the town
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

//***********
// create
//***********
create() {
  ::create();
  SetIntShort("The main plaza");
  SetIntLong(
    "This place is part of the main plaza of the town. A signpost is "
    "standing here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({580,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");
  AddVItem( ([
    P_IDS: ({"signpost"}),
    P_ADS: ({"old"}),
    P_LONG: ({"It is old and nearly rotten.\n",
            "It is old and nearly rotten, but still readable.\n"
            }),
    P_READ_MSG:
            "Some words can be read on the signpost:\n"
            "    nort       - voodoo sh p\n"
            "     outh eas  - gen ral shop\n"
            "    south  s   - temp e  f Xarx s\n"
            "    west       - harbo r\n"
            "    east       - main laz\n"]) );

  /* Exits */
  AddExit("north",    "./mainplazanw");
  AddExit("northwest","./to_plate");
  AddExit("east",     "./mainplazam");
  AddExit("south",    "./mainplazasw");
  AddExit("west",     "./maingate");

  Set(P_INT_WIZMSG,
    "%^RED%^check the sign msg, check the coords, "
    "add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

