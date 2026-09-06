inherit "/std/room";
#include "path.h"
#include <rooms.h>

create() {
  ::create();
  SetIntShort("A hilltop");
  SetIntLong(
"You are on a beautiful hilltop overlooking Nightfall City. "
"To the east you see a vast sea, with quays and docks along "
"the coast.  Off to the west you see the Nightfall Clocktower in "
"the distance.  It is beautiful here.\n");
  AddDetail(({"nightfall","nightfall city","city","town"}),
  "The large capital of the world.\n");
  AddDetail("capital","It is Nightfall City.\n");
  AddDetail(({"hill","hilltop"}),"You reached the top of a hill.\n");
  AddDetail("sea","blue water, flying seagulls...\n");
  AddDetail("water","Blue it is.\n");
  AddDetail(({"seagull","seagulls"}),"They are flying far away over the sea.\n");
  AddDetail(({"quays","quay"}),"Ships dock there.\n");
  AddDetail(({"dock","docks"}),"The place ships leave and arive.\n");
  AddDetail(({"ship","ships"}),
  "Ships from all over the world come to Nightfall City\n");
  AddDetail(({"clocktower","nightfall clocktower","tower"}),
  "It is a high building nearly scrapping the sky. You know its sound "
"very well as it is to be heard every hour.\n");
  AddExit("down","./hill");
  AddItem(PHISH("castle"),REFRESH_HOME);
  SetIndoors(0);
}
