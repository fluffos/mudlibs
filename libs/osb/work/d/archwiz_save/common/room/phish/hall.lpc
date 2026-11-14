/*  -*- LPC -*-  */
#include "path.h"
inherit "/std/room";

int clean;

create()
{
  ::create();
  SetIntShort("A Hall");
  AddDetail(({"castle","phish's castle"}),
"This is the castle of Phish the son of Michael.\n");
  AddDetail(({"hall","main hall"}),#'IntLong);
  AddExit("south","./entrance");
  AddExit("north","./maze_entrance");
  AddExit("west","./bar");
  AddExit("east","./cemetary");
  reset();
}

reset()
{
  ::reset();
  clean=0;
  SetIntLong(
"This is the main hall of the castle. It looks quite big. If it was cleaned, "
"it would sure be a nice place.\n"
);
}


init()
{
  ::init();
  add_action("clean","clean");
}

clean(str)
{
  if (!this_player()) return 0;
  if(!present("pbroom",this_player())){
    write("You need something to clean the room with.\n");
    return 1;
  }
  if (clean == 1) {
    write ("The room is already clean an shiny.\n");
    return 1;
  } else {
    clean = 1;
    write("You clean the room... it's hard work...\n");
    show(this_player()->QueryName()+" cleans the floor.\n",this_player());
    SetIntLong(
"This is the main hall of the castle.  It is beautiful thanks "
"to "+this_player()->QueryName()+" who took the time and effort to clean it up.\n"
	      );
    return 1;
  }
}

