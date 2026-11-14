#include "path.h"
#include <moving.h>
#include <rooms.h>

inherit "/std/room";

int do_search(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Search what or where?\n"),0;
  if ((str!="bushes") && (str!="bush") && (str!="low bushes")
    && (str!="low bush")) return notify_fail(
"You eagerly search "+lower_case(str)+", but you find nothing.\n"),0;
  write("As you search the bushes, you suddenly notice that you "
        "probably could walk through them, though you'd be hurt.\n");
  show(capitalize(this_player()->QueryName())+" searches the bushes.\n");
  return 1;
}

int do_walk(string str) {
  if (!this_player()) return 0;
  if (!str) return notify_fail("Walk through what?\n"),0;
  if ((str!="through bushes") && (str!="through bush")
     && (str!="through the bushes") && (str!="through the bush")) return
    notify_fail("Walk through the bushes perhaps?\n"),0;
  if ((this_player()->QueryRace()!="elf") &&
      (this_player()->QueryRace()!="halfling") &&
      (this_player()->QueryRace()!="half-elf")) {
    this_player()->Defend(random(5)+2,DT_PIERCE,this_object());
    write("You feel thorns scratch your skin.\n");
    }
  else write("Carefully you avoid all thorns.\n");
  return this_player()->move(PARK("hunter_hide"),M_GO,"through the bushes");
}

create() {
  ::create();
  SetIntShort("Mother Fox Area");
  SetIntLong(
"Low bushes make it impossible for you to walk through "
"without scratching your legs and arms.\n");
  SetIndoors(0);
  AddDetail(({"bush","bushes","low bushes","low bush"}),
"As you look closer you see that there is a possibility to walk through "
"them. You could get hurt though.\n");
  AddRoomCmd("search",#'do_search);
  AddRoomCmd("walk",#'do_walk);
  AddExit("west","./pa4n6");
  AddExit("east","./pa2n6");
  AddExit("south","./pa3n7");
  AddExit("north","./pa3n5");
  AddItem(MONSTER("park/motherfox"),REFRESH_HOME);
}
