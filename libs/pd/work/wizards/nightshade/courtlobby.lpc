#include <std.h>
#include <tirun.h>

inherit ROOM;

string state = "closed";

void main() {
  ::create();
  set_short("Courtroom Lobby");
  set_long("Long wooden pews are dutifully lined up in two"
           " rows, creating a single path down the center of"
           " the room.  The wooden floors creak beneath the"
           " weight of each footstep.  A long red rug leads"
           " from the road entrance up to a large set of"
           " double doors set within the north wall. "
           " A small sign dangles next to the door.");
  set_properties( (["no attack" : 1,
                    "no magic" : 1,
                    "no castle" : 1,
                    "no steal" : 1,
                    "no teleport" : 1,
                    "light" : 2,
                    "indoors" : 1 ]) );
  set_exits( ([ "north" : ROOMS "courtroom",
                "south" : ROOMS "square" ]) );
  add_pre_exit_function("north", "enter_court");
}

int enter_court() {
  if(state == "closed") {
    write("You notice that the sign says that the courtroom is closed.");
    return 0;
  }
// add stuff here
  return 1;
  }
