/*
 * part of the townwall
 *
 * last changes:
 * [m] 26 jan 98 - first version
 */

// TODO: check the time-msgs?!

#include <properties.h>
#include <regions.h>
#include <coordinates.h>
#include <moving.h>
#include <nightday.h>
#include <sykorath.h>

inherit TOWNWALL;

//****************
// special details
//****************
string look_loophole() {
  return process_string(
  "You sse a little bit from the outer city looking through it. "
  "@@TimeMsg@@\n");
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("Inside the townwall");
  SetIntLong(
    "You are inside the townwall. A loophole is to the northwest. "
    "@@TimeMsg@@\n");

  SetIndoors(1);
  SetCoordinates( ({ ({540,520,5}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  // set the time msgs:
  Set(P_TIME_MSG,
    ([
    DAY_DEFAULT_MSG:
       "Some sunrays falls through it.",
    NIGHT_DEFAULT_MSG:
       "You see the stars through it.",

    // early morning messages
    ND_PREDAWN: "",
    ND_DAWN: "",
    ND_SUNRISE: "",

    // evening messages
    ND_SUNSET:
       "",
    ND_TWILIGHT:
       "",
    ND_EVENING:
       "",
    ]));

  /* details */
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"inside"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"loophole"}),
    P_LONG: #'look_loophole ]) );

  /* exits */
  AddExit("east","./town57x52");
  AddExit("southwest","./town52x54");

  Set(P_INT_WIZMSG,
    "%^RED%^add time-msgs for the other time zones, "
    "add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

