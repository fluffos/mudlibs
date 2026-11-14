/* the diamond is an item for the collector quest, please do not change
   this file, its pathname or the diamond without notifying the questdepartment
   AND Cadra */
#include "path.h"
#include <properties.h>
#include <moving.h>
#include <rooms.h>

inherit "/std/room";

int up() {
  write("You can't lift the lid. It's too heavy.\n");
  return 1;
}

int go_east() {
  object ob;
  if (!this_player()) return 0;
/*
  if (!present("stinkerx",this_player())) {
    ob=clone_object(PIROBJ("stinkc"));
    ob->move(this_player(),M_SILENT);
    }
*/
  this_player()->move(PIRATE("sew2"),M_GO,"east");
  return 1;
}

create() {
  ::create();
  SetIntShort("city sewers");
  SetIntLong(
"You're in the city sewers. There's a very bad smell in the air. "
"You don't wish to know what's swimming around your feet. The way "
"to the west is collapsed.\n");
  SetIndoors(1);
  SetBright(0);
  AddDetail(({"sewers","city sewers"}),QueryIntLong());
  AddDetail(({"smells","smell","bad smell"}),"*COUGH*\n");
  AddDetail(({"walls","wall","ceiling","ground","floor"}),
"It is DIRTY!\n");
  AddDetail(({"dirt","shit"}),"It is shit.\n");
  SetIntSmell("It smells horrible.\n");
  AddExit("up",#'up);
  HideExit("up",1);
  AddExit("east",#'go_east);
  AddItem("std/npc",REFRESH_HOME,3,
    ([P_NAME:"rat",
      P_SHORT:"a large rat",
      P_LONG:"A large stinking rat with sharp teeth.\n",
      P_LEVEL:4,
      P_HP:60,
      P_ALIGN:0,
      P_AC:3,
      P_HANDS:({({"its claws",0,3}),({"its teeth",0,6})}),
      P_AGGRESSIVE:1]));
  AddItem(PIROBJ("pldiam"),REFRESH_REMOVE);
}
