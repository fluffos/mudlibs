#include "path.h"
inherit "/std/room";

create(){
  ::create();
  SetIntShort("A Maze Entrance");
  SetIntLong(
"This is the entrance point for a maze.  There are 5 doorways marked "
"A, B, C, D and E leading to different rooms in the maze.  There is "
"also an exit to the south.\n");
  AddExit("south","./hall");
  AddExit("A","./maze/a");
  AddExit("B","./maze/b");
  AddExit("C","./maze/c");
  AddExit("D","./maze/d");
  AddExit("E","./maze/e");
 }

init(){
object map;
  ::init();
  if (!this_player()) return 0;
  if(!present("mmap",this_player())){
    write("You magically receive a nice map to the maze.\n");
    map= clone_object(PHISH("maze/map"));
    map->move(this_player());
    }
 }
