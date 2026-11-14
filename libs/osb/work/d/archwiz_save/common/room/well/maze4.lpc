#include "path.h"
#include <moving.h>

inherit "/std/room";

int exit_num;

int r0() {
  if (!this_player()) return 0;
  if (exit_num==0) {
    this_player()->move(WELL("maze5"),M_GO,"north");
    return 1;
    }
  this_player()->move(WELL("maze3"),M_GO,"north");
  return 1;
}

int r1() {
  if (!this_player()) return 0;
  if (exit_num == 1) {
    this_player()->move(WELL("maze5"),M_GO,"south");
    return 1;
    }
  this_player()->move(WELL("maze2"),M_GO,"south");
  return 1;
}

int r2() {
  if (!this_player()) return 0;
  if (exit_num == 2) {
    this_player()->move(WELL("maze5"),M_GO,"east");
    return 1;
    }
  this_player()->move(WELL("well"),M_GO,"east");
  return 1;
}

int r3() {
  if (!this_player()) return 0;
  if (exit_num == 3) {
    this_player()->move(WELL("maze5"),M_GO,"west");
    return 1;
    }
  this_player()->move(WELL("well"),M_GO,"west");
  return 1;
}

create() {
  ::create();
  SetIntShort("A maze");
  SetIntLong(
"In a maze.\n");
  AddExit("north",#'r0);
  AddExit("south",#'r1);
  AddExit("east",#'r2);
  AddExit("west",#'r3);
  reset();
}

reset() {
  ::reset();
  exit_num=random(4);
}
