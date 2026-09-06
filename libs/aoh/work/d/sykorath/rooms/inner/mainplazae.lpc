/* part of the mainplaza of the town
 * made by magictcs - 08 jan 97
 *
 * last changes:
 * 
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("East of the main plaza");
  SetIntLong(
    "This place is part of the main plaza of the town.\n"
    "A signpost is standing here.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({620,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");
  AddVItem( ([
    P_IDS:  ({"city"}),
    P_ADS:  ({"inner"}),
    P_LONG: "This place is part of the inner city of the town.\n" ]) );
  AddVItem( ([
    P_IDS: ({"signpost","very old signpost"}),
           // aehems (adding as ads didn't worked!)
           // P_ADS: ({"old","very old","rotten"})
    P_ADS: ({"old","rotten"}),
    P_LONG: ({"It is a very old and rotten signpost.\n",
            "It is too rotten to read the word on it.\n"
            }),
    P_READ_MSG:
            "It is too rotten to read the words on it.\n"]) );

  /* Exits */
  AddExit("north","./mainplazane");
  AddExit("west", "./mainplazam");
  AddExit("east", "./smithy");
  AddExit("south","./mainplazase");

  Set(P_INT_WIZMSG,
    "%^RED%^check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

