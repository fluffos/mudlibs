/* part of the inner city
 *
 * last changes:
 * [m] 25 jan 98 - first version
 */

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <ansi.h>
#include <skills.h>
#include <sykorath.h>

inherit SY_STREET;

//****************
// search handling
//****************
int OnSucceedSearchingWall() {
  write("Which wall do you want to search? The north, south or west wall?\n");
  return 1;
}
int OnSucceedSearchingDirt() {
  write("Better search the walls.\n");
  return 1;
}

int OnSucceedSearchingWwall() {
  write("You found an inscription:\n"
    "  -> Search a big table and read the marks! <-\n");
  return 1;
}
int OnFailSearchingWwall() {
  write("Hmm, there is nothing hidden at this wall.\n");
  return 1;
}
int OnSucceedSearchingNwall() {
  write("There is nothing on interest hidden.\n"); 
  return 1;
}
int OnFailSearchingNwall() {
  write("You see nothing special.\n");
  return 1;
}
int OnSucceedSearchingSwall() {
  write("You find nothing.\n");
  return 1;
}
int OnFailSearchingSwall() {
  write("You search, but get only dirty fingers.\n");
  return 1;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("A dark road");
  SetIntLong(
    "A dark end of the street. The way to the east leads back to the main "
    "plaza. It is really dark here. All the walls of other houses are "
    "blocking the light.\n");

  SetIndoors(0);
  SetCoordinates( ({ ({540,560,0}), C_SYKORATH }));
  SetRegion(REGION_CITY);
  SetIntLight(-20);

  SetMap("inner");

  /* details */
  AddVItem( ([
    P_IDS:  ({"road","street"}),
    P_ADS:  ({"dark"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"end"}),
    P_ADS:  ({"dark","dead"}),
    P_LONG: #'IntLong ]) );
  AddVItem( ([
    P_IDS:  ({"way","east","way back"}),
    P_LONG: "You can go back to the main plaza there.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"plaza","mainplaza"}),
    P_ADS:  ({"main"}),
    P_LONG: "You can't see the main plaza from here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"wall","walls"}),
    P_LONG: "You see walls of three houses to the north, west and "
            "south. All walls are covered with dirt. But you see no door "
            "or entry here.\n" ]) );
  AddVItem( ([
    P_IDS:  ({"house","houses"}),
    P_ADS:  ({"other","three"}),
    P_LONG: "One house stands north, another south and one can be seen to "
            "the west.\n" ]) );

  /* commands */
  AddSkill(SK_SEARCH,"wall",0,({"wall","walls"}));
  AddSkill(SK_SEARCH,"wwall",50,({"west wall","wall west"}));
  AddSkill(SK_SEARCH,"nwall",50,({"north wall","wall north"}));
  AddSkill(SK_SEARCH,"swall",50,({"south wall","wall south"}));
  AddSkill(SK_SEARCH,"dirt",0,({"dirt","dirty wall","dirty walls"}));

  /* Exits */
  AddExit("east","./libentry");

  Set(P_INT_WIZMSG,
    "%^RED%^add something special, add details!%^RESET%^\n"
    "then remove this message :)\n"
  );
}

