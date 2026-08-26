#include "../defs.h"
object lee;
inherit ROOM;
void create() {
  seteuid(getuid());
  set("author", "Waxer");
  set("light", 1);
  set("short", "The Janitor's Closet.");
set("long", @ENDLONG
This is the janitors closet.  The air is dank and very hard to breathe.
Space in here is small, leaving very little room for movement.
ENDLONG
);
   set("objects", ([
    OBJ(bucket) : 1,
]) );
  set("item_desc", ([ "space" : "There is little space in this room for breathing, much less
movement.\n",
]));
  set("exits", ([
    "north" : ROOMS(office),
 ]) );
  ::create();
}
void reset(){
  if(!lee){
    lee=clone_object(MON(lee));
    lee->move(TO);
  }
::reset();
}