/* part of the mainplaza of the town
 * made by magictcs - 22 may 97
 *
 * last changes:
 * [m] 08 jan 97 - remade, added advertising pillar
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <sykorath.h>

inherit BASEROOM;

string message;

//*******************************
// handling of advertising pillar
//*******************************
string SetPillar(string m) { return message=m; }
string QueryPillar() { return message; }

string look_advertising_pillar() {
  return
    "It is a huge advertising pillar. You will find some useful "
    "informations on it. You can read it.\n";
}

string read_advertising_pillar() {
  return message;
}

//*******
// create
//*******
create() {
  ::create();
  message="No executions, no torturings the next days.\n";
  SetIntShort("The main plaza");
  SetIntLong("This place is part of the main plaza of the town. "
    "An advertising pillar stands in the middle of the place.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({600,580,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"plaza","place"}),
    P_ADS:  ({"this","main"}),
    P_LONG: #'IntLong ]) );
  AddDetail("town","You are standing inmids the town.\n");
  AddVItem( ([
    P_IDS:  ({"pillar","information","informations"}),
    P_ADS:  ({"advertising"}),
    P_LONG: #'look_advertising_pillar,
    P_READ_MSG: #'read_advertising_pillar,
    ]) );

  /* Exits */
  AddExit("north",    "./courthouse");
  AddExit("west",     "./mainplazanw");
  AddExit("south",    "./mainplazam");
  AddExit("east",     "./mainplazane");

  Set(P_INT_WIZMSG,
    "%^RED%^adds better long and add details!%^RESET%^\n"
    "A wizard can set the message of the pillar by calling:\n"
    "    xcall $h->SetMessage(\"text\\n\")\n");
}

