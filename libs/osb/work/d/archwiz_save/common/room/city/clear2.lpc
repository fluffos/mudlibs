#include <moving.h>
#include "path.h"

inherit "std/room";

int go_south() {
  if (!this_player()) return 0;
  this_player()->move(CITY("clearing"),M_GO,"to an unseen direction");
  return 1;
}
 
int do_enter(string str) {
  if (!str) return 0;
  if (str!="hole") 0;
  if (!this_player()) return 0;
  this_player()->move(PIRATE("dark0"),M_GO,"into one of the bushes.\n");
  return 1;
}

create() {
 ::create();
 SetIntShort("Yet another clearing");
 SetIntLong(
"This is a small clearing all surrounded by bushes. Some trees are to the west "
"where the forest gets very dense. The ground is covered with high grass "
"that bows in the wind.\n");
 AddDetail( ({"bushes"}),
"The bushes get sparse to the south. One of the bushes looks extremely thick.\n");
 AddDetail("bush","There is a hole under it.\n");
 AddDetail(({"hole","dark hole"}),
"You think you could manage to enter this dark hole. But what will wait "
"for you there?\n");
 AddDetail( ({"tree","trees"}),"The trees are very high and old.\n");
 AddDetail( ({"forest"}),"A dark forest is to the west.\n");
 AddDetail( ({"grass"}),"The grass bows in the wind.\n");
 SetIntSmell("You smell the flavour of blossoms.\n");
 SetIntNoise("You hear the birds singing in the trees.\n");
 SetIndoors(0);
 AddExit("south",#'go_south);
 AddExit("leave",#'go_south);
 AddExit("down",PIRATE("dark0"));
 AddExit("enter",#'do_enter);
 HideExit("enter",1);
 HideExit("down",1);
 HideExit("leave",1);
 HideExit("south",1);
}
