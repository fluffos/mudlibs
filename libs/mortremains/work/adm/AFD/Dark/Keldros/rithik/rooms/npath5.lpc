#include "../defs.h"
inherit ROOM; 
void create() {
  seteuid(getuid());   
 set_outside();
  
  set("author", "Waxer");  
  set("light", 1);
  set("short", "The entrance to an ancient battleground.");
set("long", @ENDLONG
This appears to be the site of an ancient battle.  Skeletons covered in grime
and dirt litter the ground.  The trees surround you, but it appears you
could go to either the east or west.
ENDLONG
);
set("item_desc", ([
"skeletons" : "These are the remains of humanoids, both human and dwarf.\n",
"trees" : "The trees are dark and twisted, warped beyond what nature would create.\n",
]) );
set("objects", ([ MON(udwarf) : 1, ]) );
set("exits", ([
"east" : "/u/w/waxer/cephrin/rooms/bat",
  "west" : ROOMS(b_ground2),
  "south" : ROOMS(npath4),
]) );
set("pre_exit_func", ([
     "east" : "guarded",
     "west" : "guarded",
]) );
::create();
}
int guarded() {
  if (present("dwarf", TO)) {
    write("The dwarf begs you not to go that way.\n");
    write("The dwarf says: 'Please, go back from whence you came.'\n"); 
  return 1;
  }
  return 0;
}
