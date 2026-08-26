#include "../defs.h"

inherit ROOM;

void create() {
  seteuid(getuid());

  set("author", "Gendor");

  set("light", 1);


  set("short", "Outside the Mayor's.");

set("long", @ENDLONG
A large, white, marble house stands before you.  It's columns extend up about
8 feet.  The house is very immaculate, and it looks very well built.  The
windows of the house are shuttered, and all but one of them are closed.
ENDLONG
   );

  set("item_desc", ([
"window" : "You can see traces of movement inside the room.\n",
"columns" : "These are white, clyndrical, columns.\n",
   ]) );

  set("smell", ([
    "default" : "The scent of meat is gone, all you smell now is honeysickles.\n",
  ]) );
  set("listen", ([
   "default" : "You hear muffled voices through the opened window.\n",

  ]) );

  set("exits", ([
    "north" : ROOMS(mayors1),
    "south" : ROOMS(maytem),


  ]) );
set("objects", ([
    MON(guard) : 1,
    MON(guard2) : 1,
  ]) );
  ::create();
}
void make_corpse()
 {
  object corpse;
  tell_object(TO, "Shards of glass fly at you from the second story building above you followed by the screaming body of the mayor!\n");
   corpse = clone_object("/obj/std/corpse");
   corpse->set("short", "Corpse of The mayor");
   corpse->move(TO);
  corpse->set("long", "This is the dead body of The mayor.\nHe was killed by a rather nasty fall.\n");
 return;
}