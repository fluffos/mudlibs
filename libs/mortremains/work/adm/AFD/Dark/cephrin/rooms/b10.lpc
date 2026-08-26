#include "../defs.h"

inherit ROOM;

void create(){
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set_outside("zone", "2");
  set("short", "the edge of the woods");
  set("long", @EndDesc
A small dirt clearing that serves as a path runs through
a small grouping of trees.  Pine and cedar release kind odors
that make one feel comfortable, even in the midst of the gruesome
battlefield which surrounds this place.
EndDesc);

set("objects", ([ MON(ghoul) : 2, ]));
set("exits", ([ "south" : ROOMS(b8), ]));
::create();
}
