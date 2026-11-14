// the healer room for the madmonks guild
// made by Magictcs - 11  may 97
// the room will not log missing details

// TODO: add some food

#include <rooms.h>
#include "/p/guilds/madmonks/madmonks.h"
inherit "/room/pub";

// not the normal 'read menu'  :)
string readmenu() {
  return
  menu+"Just 'order' or 'buy' the food/drinks.\n";
}

void create() {
  ::create();
  SetIntShort("The small pub of the guild");
  SetIntLong(
  "This is the pub of the Madmonks Guild. You can 'order' or 'buy' drinks\n"
  "and food here.\n"
  "You have also the possibility to 'buy [drink|food] for [someone].\n"
  "On the south wall hangs a small list.\n"
  "To the west lies the local healer office. There is a sign on the west\n"
  "wall. North is the room of our main-trainer.\n");

  /* details */
  AddDetail(({"pub","small pub"}),#'IntLong);

  RemoveRoomCmd("read");                 // remove the standard 'read menu'
  AddDetail(({"list","small list","list on wall","small list on wall",
    "list on the wall","small list on the wall","list on south wall",
    "small list on south wall","list on the south wall",
    "small list on the south wall"}),
    "A small list that contains the menu of this pub.\n",
    "A small list that contains the menu of this pub.\n"
    "You can read it.\n");

  AddDetail(({"menu","menu of pub","menu of this pub"}),
    "Better read it.\n");
  AddReadMsg(({"menu","menu of pub","menu of this pub"}),
    #'readmenu);

  AddReadMsg(({"list","small list","list on wall","small list on wall",
    "list on the wall","small list on the wall","list on south wall",
    "small list on south wall","list on the south wall",
    "small list on the south wall"}),#'readmenu);

  AddDetail(({"sign","sign on wall","sign on the wall",
    "sign on the west wall"}),
    "The healer office!\n");
  AddReadMsg(({"sign","sign on wall","sign on the wall",
    "sign on the west wall"}),
    "The healer office - open during night!\n");

  AddDetail(({"healer","healer office","office"}),
    "The healer office can be found to the west.\n"
    "It is closed during the day.\n");
  AddDetail("west","There is the healer office.\n");
  AddDetail("south","There is a wall with a small list.\n");
  AddDetail("north","You can go there to the room of our main-trainer.\n");

  AddDetail(({"wall"}),
    "Try to look at a specific wall.\n");
  AddDetail(({"west wall","wall west"}),
    "A sign is hanging there.\n");
  AddDetail(({"south wall","wall south"}),
    "A small list is hanging on this wall.\n");

  AddExit("north",MONKROOM("statstrain"));
  AddExit("west",MONKROOM("healer"));

  SetIndoors(1);

  /* drinks */
  AddDrink("beer",1,3,5,0);
  AddDrink("special",10,10,7,0);
  AddDrink("firebreather",15,20,10,0);
  AddDrink(({"coke mixed with rum","coke","rum"}),50,40,30,0);
  AddDrink(({"sprite mixed with vodka","vodka","sprite"}),60,45,35,0);

  /* food */
  AddFood(({"ham and eggs","ham","eggs"}),8,14,229,0);
}

