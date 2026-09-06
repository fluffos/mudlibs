/*
 * part of the townwall - the south tower (platform stage)
 *
 * last changes:
 * [m] 17 jun 97 - first version
 * [m] 21 jan 98 - remade
 */

// TODO: use the ball for a quest?!

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit TOWNWALL;

//***************
// reset the ball
//***************
void new_ball() {
  show_room(TO,"The silver ball rolls from one side to the other.\n");
}

//**************
// special reset
//**************
reset() {
  // called before reset (it reclones the ball!)
  if (!present("__tower_silver_ball__")) {
    show_room(TO,
      "A small ball falls from the sky and missed you shortly.\n");
  }
  ::reset();
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("On the platform of the south tower");
  SetIntLong(
    "You are standing on the platform of this tower. To the north you "
    "see the north tower of the townwall of the inner city. A staircase "
    "leads down.\n");
  SetIndoors(0);
  SetCoordinates( ({ ({500,620,10}), C_SYKORATH }));
  SetRegion(REGION_CITY);

  /* details */
  AddVItem( ([
    P_IDS:  ({"tower","south tower","tower south"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"city"}),
    P_ADS:  ({"inner","outer"}),
    P_LONG: "If you look around you will see some parts of the inner city "
            "to the east and some parts of the outer city to the "
            "west.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"platform"}),
    P_LONG: "You are standing on it.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"north tower","tower north"}),
    P_LONG: "You see this tower to the north. It is not far from here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"towers"}),
    P_ADS:  ({"two"}),
    P_LONG: "You are in one on the both towers.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"townwall"}),
    P_ADS:  ({"high"}),
    P_LONG: "This tower is part of the high townwall.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"gate","towngate"}),
    P_ADS:  ({"inner"}),
    P_LONG: "You can't see it from here!\n" ]) );
  AddVItem( ([
    P_IDS:  ({"staircase"}),
    P_ADS:  ({"oak","wooden","old"}),
    P_LONG: "It is the old oak staircase where you come from. You can use "
            "it to go back to the south tower.\n" ]) );

  /* Items */
  AddItem("/std/thing",REFRESH_REMOVE, ([
    P_IDS:    ({"ball","__tower_silver_ball__"}),
    P_ADS:    ({"silver","small"}),
    P_SHORT:  "a small silver ball",
    P_LONG:   "It is a small silver ball. The surface is reflecting your "
              "surroundings. You've never seen such a nice ball before. "
              "You don't know what is this ball good for.\n",
    P_WEIGHT: 450,
    P_INFO:   "Cloned by Magictcs-Laboratories (C) 1998\n",
    P_VALUE:  300,
    P_HELP_MSG: "It is usefull for playing some games.\n",
    ]), 1,"new_ball");

  /* exits */
  AddExit("down", "./towers_up");
}

