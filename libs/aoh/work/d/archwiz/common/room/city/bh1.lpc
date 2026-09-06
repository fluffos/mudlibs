inherit "std/room";
#include "path.h"

create() {
  ::create();
  SetIntShort("A path");
  SetIntLong(
"The path forks. You see a path leading northeast and southwest. In front "
"of you another path leads through the bushes to the northwest.\n");
  SetIndoors(0);
  AddDetail(({"bushes","bush"}),"The the bushes around are always green.\n");
  AddDetail("pathes",
"One leads northeast, one southwest, and one leads northwest.\n"); 
  AddDetail("path","Which one?\n");
  AddDetail(({"northwest path","another path"}),
"It leads towards a hot and dry land.\n");
  AddDetail("northeast path","You feel hot air coming from this direction.\n");
  AddDetail("southwest path","It leads to the capital of the world.\n");
  AddDetail(({"capital","nf-city","nightfall city","city"}),
"It is somewhere south of you.\n");
  AddDetail(({"hot land","dry land","hot and dry land"}),
"It seems to be to the north.\n");
  AddDetail("fork","You can't eat with THIS fork!\n");
/*
  AddExit("northeast","/d/orient/common/room/clondike/s23");
  AddExit("northwest","/d/orient/common/room/clondike/s13");
*/
  AddExit("southwest","./bh2");
  AddExit("north", "/players/mica/dp/rooms/darkportal/portal_in" );
}
