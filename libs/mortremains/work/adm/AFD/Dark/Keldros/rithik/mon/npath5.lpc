#include "../defs.h"
inherit ROOM; 
void create() {
  seteuid(getuid());   
 set_outside();
::create();  
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
set("objects", ([ MON(udwarf), ]) );
set("exits", ([
  "east" : ROOMS(b_ground1),
  "west" : ROOMS(b_ground2),
  "south" : ROOMS(npath4),
]) );
