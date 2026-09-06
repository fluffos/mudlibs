// part of the town
// made by magictcs - 3 jul 97
// TODO: update coords

#include <properties.h>
#include <moving.h>
#include <npc.h>
#include <regions.h>
#include <coordinates.h>
#include <sykorath.h>

inherit BASEROOM;

//**************
// break window?
//**************
int destructwindow(string str) {
  notify_fail("What do you want to do?\n");
  if (!str) return 0;
  if (member(({"window","window of wall","south window","window south",
    "window of south wall"}),str)!=-1) {
    write(
      "You try to break the window in the south wall. But you are not strong\n"
      "enough. The glass of the windows is made of a special sort of glass.\n"
      "Even with a hammer or something like that you will be not able to\n"
      "break it.\n");
    return 1;
  }
  return 0;
}

//*******
// create
//*******
create() {
  ::create();
  SetIntShort("In a huge house");
  SetIntLong(
    "You are standing in a huge house. This must be the sitting room of the\n"
    "house. The wall to the south contains a window.\n"
    "A stony staircase leads up.\n");
  SetIndoors(1);
  SetCoordinates( ({ ({0,0,0}), C_SYKORATH }));
  Set(P_REGION,REGION_CITY);

  /* details */
  AddDetail(({"house","huge house"}),#'IntLong);
  AddDetail(({"sitting room","room"}),
    "The sitting room contains some valueable items.\n");
  AddDetail(({"wall","wall south","south wall"}),
    "This wall contains a window. You can look through it.\n");
  AddDetail(({"window","through window","throught he window"}),
    "Uhh how ugly. There is a huge tower to the south. You can't see\n"
    "anything! Seems that the tower is built after building this house.\n");
  AddDetail(({"tower","huge tower"}),
    "The tower blocks the view throught he window.\n");
  AddDetail(({"items","item","valueable items","valueable items"}),
    "You see a couch, a table and a wardrobe.\n");
  AddDetail(({"staircase","stony staircase"}),
    "You can go to an upper story of the house there.\n");
  AddDetail(({"glass","special glass","glass of special sort","special sort",
    "glass of window","glass of the window"}),
    "This glass is glass of a special sort. It is unsmashable. Noone of\n"
    "world is able to break these glass.\n");

  /* items */
  AddItem(OBJ("sofa"),REFRESH_NONE);
  AddItem(OBJ("table"),REFRESH_NONE);
  AddItem(OBJ("wardrobe"),REFRESH_NONE);

  /* commands */
  AddRoomCmd("smash",#'destructwindow);
  AddRoomCmd("destruct",#'destructwindow);
  AddRoomCmd("break",#'destructwindow);

  /* exits */
  AddExit("up","./houseu1");
  AddExit("west","./housew1");
}

