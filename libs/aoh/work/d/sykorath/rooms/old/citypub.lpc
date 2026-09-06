// part of the town
// made by magictcs - 18 jun 97
// TODO: add exits,more details,drinks
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit "/room/pub";

create() {
  ::create();
  SetIntShort("the city pub");
  SetIntLong(
    "You are standing in the biggest pub of this city.\n"
    "You can order drinks here or 'buy [drink] for [somebody]. To see what\n"
    "you can drink here, just 'read menu'! Cheers!\n"
    "The exit lies to the west, a funny doorway leads east. "
    "In one corner a stairway leads up. There is a sign attached to "
    "one wall.\n");
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"pub","city pub","biggest pub","biggest city pub"}),#'IntLong);
  AddDetail("wall",
    "A wooden sign is attached to the wall.\n");
  AddDetail("walls",
    "The walls look like everywhere. On wall has a sign attached to it.\n");
  AddDetail(({"sign","wooden sign","runes","some runes"}),
    "It is a wooden sign. Some runes are carved into the sign, but it is "
    "still readable.\n");
  AddReadMsg(({"sign","wooden sign","runes","some runes"}),
    "You read the sign:\n"
    "  /-----------------------------\\\n"
    "  |                             |\n"
    "  |  Drink as much as you can!  |\n"
    "  |                             |\n"
    "  \\-----------------------------/\n" );


  /* drinks */
  AddDrink("special",10,8,10,0);
  AddDrink("coffee",0,2,-2,20);
  AddDrink("firebreather",25,20,12,140);
  AddDrink("beer",0,2,2,3);
  AddDrink("scotch",20,20,10,100,
    "As you drink, warm fires run through your veins.");
  SetMenuStr("The more you drink the more fun you have!\n");

  /* items */
  // yeah a new go player problem :)
//  AddItem(OBJ("level_list"), REFRESH_REMOVE);
  AddItem(QUEST("go/rules"), REFRESH_NONE);
  AddItem(QUEST("go/go_player"),REFRESH_HOME);
  AddItem(NPC("schluck"),REFRESH_HOME);

  /* exits */
  AddExit();
}

