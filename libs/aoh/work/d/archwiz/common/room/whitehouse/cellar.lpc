inherit "std/room";

#include <properties.h>
#include <moving.h>
#include <rooms.h>
#include "path.h"

#define UPROOM (WHITEHOUSE("living_room"))

int move_up() {
  if (call_other(UPROOM,"trap_status"))
    this_player()->move(UPROOM,M_GO,"up");
  else
    write("The trap door is closed.\n");
  return 1;
}

int do_open(string str) {
  if (str != "trap door") return 0;
  if (call_other(UPROOM,"trap_status"))
    write("It's already open!\n");
  else {
    write("Sorry, the trap door can't be open from this side.\n");
    write("I suggest you search for another exit.\n");
    }
  return 1;
}

int do_close(string str) {
  if (str != "trap door") return 0;
  if (!call_other(UPROOM,"trap_is_open"))
    write("It's already closed!\n");
  else
    write("You can't do that from here.\n");
  return 1;
}

describe_trap() {
  return (UPROOM->trap_status() ?
    "The heavy trap door is open.\n" :
    "The heavy trap door is closed.\n");
}

QueryIntLong()
{
	return (
"You are in the cellar. A gloomy corridor leads east. You can see "
"footsteps in the dust that covers the floor. You consider this a bad omen. "
"A crawlway is to the south and a twisty passage leads to the west. Above "
"your head you notice a trap door in the ceiling which is "+
		(UPROOM->trap_status() ?
		"open.\n" :
		"closed.\n"));
}

create() {
  ::create();
  SetIntShort("Cellar");
  AddDetail(({"footsteps","steps","footstep","footprint","footprints"}),
    "The footprints are leading eastward!\n");
  AddDetail(({"trap","trap door"}),#'describe_trap);
  AddDetail(({"cellar"}),#'IntLong);
  AddDetail(({"corridor","gloomy corridor"}),"It leads further east.\n");
  AddDetail(({"dust"}),"You sneeze loudly.\n");
  AddDetail(({"crawlway","way"}),"It is to the south.\n");
  AddDetail(({"passage","twisty passage"}),"It leads west.\n");
  AddDetail(({"ceiling"}),"There's a trap door in it.\n");
  AddExit("east","./trollroom");
  AddExit("west","./maze1");
  AddExit("south","./crawl");
  AddRoomCmd("up",#'move_up);
  AddRoomCmd("open",#'do_open);
  AddRoomCmd("close",#'do_close);
}


tell_all(str) {
	tell_room(this_object(), str);
}
