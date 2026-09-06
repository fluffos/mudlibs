/* 
 * part of the graveyard of the outer city
 *
 * introduced:
 * Magictcs 09 march 98 - first version
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
  SetCoordinates( ({ ({780,600,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  AddNowayMsg(({"northwest","north","northeast","west","east"}),
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
    P_LONG: "The ground is covered with some dirt.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"dirt"}),
    P_ADS:  ({"some"}),
    P_LONG: "It's not really useful for anything.\n" ]) );

  /* skills+commands */
  AddSkill(SK_SEARCH,"wall",20,vitem_wall);
  AddSkill(SK_SEARCH,"ground",20,({"ground"}));
  AddSkill(SK_SEARCH,"dirt",20,({"dirt","some dirt"}));
  AddSkill(SK_SEARCH,"grave",0,({"grave","graves"}));

  /* exits */
  AddExit("south",    "./graveyard5");
  AddExit("southwest","./graveyard2");
  AddExit("southeast","./graveyard8");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, "
    "check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

