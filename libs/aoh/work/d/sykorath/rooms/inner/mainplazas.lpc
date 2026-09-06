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

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("The main plaza");
  SetIntLong("This place is part of the main plaza of the town. "
    "To the south you see a house. A huge sign is nailed above the "
    "entrance.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");
  AddDetail("entrance",
    "It is just a normal entrance to another house to except that "
    "there is a huge sign nailed above it.\n");
  AddVItem( ([
    P_IDS:  ({"house"}),
    P_NOISE: "Yes, the noise is coming from the house.\n",
    P_LONG: "A house is standing there. The house is a little bit larger "
            "than the normal home for usual inhabitants. Maybe it is not the "
            "home of someone? You hear some noises coming from there.\n"]) );
  AddVItem( ([
    P_IDS:  ({"sign"}),
    P_ADS:  ({"huge"}),
    P_LONG: "An huge sign, you should read it!\n",
    P_READ_MSG: "You read the sign: %^BLUE%^GENERAL SHOP%^RESET%^\n" ]) );
  AddVItem( ([
    P_IDS:  ({"south"}),
    P_LONG: "A house with a huge sign nailed above the entrance is "
            "standing there.\n" ]) );

  /* Exits */
  AddExit("north",    "./mainplazam");
  AddExit("west",     "./mainplazasw");
  AddExit("south",    "./mainshop");
  AddExit("east",     "./mainplazase");

  Set(P_INT_WIZMSG,
    "%^RED%^check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

