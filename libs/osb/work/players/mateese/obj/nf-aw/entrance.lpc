inherit "d/archwiz/common/std/room";
#include <properties.h>

void create() {
	
  ::create();
    
  SetIntShort("Entrance to the LPC Dungeons");
  SetIntLong(
"You are at the Entrance to the LPC Dungeons.\n" +
"To the north is the dungeon of room examples, "+
"to the east is the room of thing examples. "+
"A crawlway leads south, and there's a hole in the floor leading down.\n"
             );
  AddExit("up",    "/d/archwiz/common/lpc/office"); 
  AddExit("north", "/d/archwiz/common/lpc/exm/xroom1");
  AddExit("east",  "/d/archwiz/common/lpc/exm/xthingroom");
  AddExit("south", "/d/archwiz/common/lpc/exm/crawlway");
  AddExit("down",  "/players/mateese/room/elevcave3");
  /* SetIntLight(1); */
}

