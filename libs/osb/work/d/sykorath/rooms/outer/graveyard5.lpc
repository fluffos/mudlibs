/* 
 * part of the graveyard of the outer city
 *
 * introduced:
 * Magictcs 02 march 98 - first version
 *
 * updated:
 * 
 */

// TODO: add more details,exits

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

//*******
// create
//*******
create() {
  string vitem_wall;
  ::create();
  SetIntShort("On a graveyard");
  SetIntLong(
    "You are standing on an old graveyard. "
    "The graveyard is surrounded by a small wall.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({780,620,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  AddNowayMsg(({"northwest","northeast","southeast"}),
    "You bump against the small wall.\n");

  SetMap("outer");

  /* details */
  AddVItem( ([
    P_IDS:  ({"graveyard","yard"}),
    P_ADS:  ({"old"}),
    P_LONG: #'IntLong ]) );
  vitem_wall=AddVItem( ([
    P_IDS:  ({"wall"}),
    P_ADS:  ({"small","rotten"}),
    P_LONG: "The wall is nearly rotten, but still around one "
            "metres huge.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"grave","graves"}),
    P_LONG: "All graves are closed. Better do not open them!\n" ]) );
  AddVItem( ([
    P_IDS:  ({"ground"}),
    P_LONG: "The ground is covered with some moss.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"moss"}),
    P_ADS:  ({"some"}),
    P_LONG: "It's not really useful for anything.\n" ]) );

  /* skills+commands */
  AddSkill(SK_SEARCH,"wall",20,vitem_wall);
  AddSkill(SK_SEARCH,"ground",20,({"ground"}));
  AddSkill(SK_SEARCH,"moss",20,({"moss","some moss"}));
  AddSkill(SK_SEARCH,"grave",0,({"grave","graves"}));

  /* exits */
  AddExit("west",     "./graveyard2");
  AddExit("north",    "./graveyard7");
  AddExit("east",     "./graveyard8");
  AddExit("south",    "./graveyard3");
  AddExit("southwest","./graveyard1");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, "
    "check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

