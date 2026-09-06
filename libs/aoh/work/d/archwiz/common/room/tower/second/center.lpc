inherit "/std/room";

#include "path.h"
#include <rooms.h>
#include <properties.h>

string 	signtext;

void create() {
  ::create();
  SetIntShort("The center of the second level in the Tower of Administration");
  SetIntLong(
"You are at the center of the second level in the Tower of Administration. "
"This is the place of the central Domain Board. Corridors lead to the north, "
"south, east and west. Every Domain Lord has an office on this floor. In the "
"offices the domains are described and plans for the future will be discussed. "
"Marble stairs leads up and down. The whole room is glowing in a warm light. "
"There is a big sign on the wall.\n");
  AddExit("west","./west1");
  AddExit("north","./north1");
  AddExit("east","./east1");
  AddExit("south","./south1");
  AddExit("up",TOWER("third/center"));
  AddExit("down",TOWER("center"));
  AddItem("/std/board",REFRESH_HOME,
    ([P_SHORT:"The Central Domain Board",
      P_LONG:"This is the general domain board of Nightfall. "
"It just carries the group 'd'.\n",
      "Groups":(({"d"}))]));
  signtext =
"                   Domains   -   A Short Introduction                     \n" +
"                                                                          \n" +
"A domain is a landscape with a theme where several wizards program in.    \n" +
"It may be an area with a town and the surroundings or something else.     \n" +
"A domain might have a size of about 100x100 km.                           \n" +
"                                                                          \n" +
"For each Domain there is a Domain Lord, the Ruler of the domain who is    \n" +
"resposible for things going on there. The Lord has write access to all    \n" +
"files of the domain.                                                      \n" +
"When an old Lord leaves there has to be elected a new one.                \n" +
"                                                                          \n" +
"If you want to found a new domain, write down a concept. Then gather some \n" +
"other wizards around you(at least three wizards must be in a new domain). \n" +
"Then contact the Archwizard of Building, a God, or an other Archwizard.   \n" +
"                                                                          \n";
  AddDetail("sign", signtext);
/*
	AddRoomCmd("read", "read");
*/
}

init() { ::init(); add_action("read", "read"); }

varargs int read(string str) {
  if(!str) return(0);
  if(lower_case(str) == "sign") {
    write(signtext);
    return(1);
  }
  return(0);
}        
