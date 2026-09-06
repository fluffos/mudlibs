/* 
 * part of the graveyard of the outer city
 *
 * introduced:
 * Magictcs 02 jul 97 - first version
 *
 * updated:
 * Magictcs - 17 feb 98 - remade, added skills
 */

// TODO: add more details,exits
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <skills.h>
#include <sykorath.h>

inherit BASEROOM;

//*******
// skills
//*******
int OnSucceedSearchingGrave() {
  write("Which graves? There are no graves here!\n");
  return 1;
}

//*******
// create
//*******
create() {
  string vitem_wall;
  ::create();
  SetIntShort("Entrance of a graveyard");
  SetIntLong(
    "You are standing on an old graveyard. It is the entrance of it. "
    "The exit is to the west. The graveyard is surrounded by a small "
    "wall.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({760,640,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  AddNowayMsg(({"northwest","southwest"}),
    "You bump against the small wall.\n");

  SetMap("outer");

  /* details */
  AddVItem( ([
    P_IDS:  ({"entrance"}),
    P_LONG: "It is the place where you stand actually.\n" ]) );
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
    P_IDS:  ({"exit"}),
    P_LONG: "You can leave the graveyard by going west.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"grave","graves"}),
    P_LONG: "It is the entrance, no graves are here.\n" ]) );
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
  AddExit("west", "./74x64");
  AddExit("north",    "./graveyard2");
  AddExit("northeast","./graveyard5");
  AddExit("east",     "./graveyard3");
  AddExit("south",    "./graveyard4");
  AddExit("southeast","./graveyard6");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, "
    "check the coords, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

