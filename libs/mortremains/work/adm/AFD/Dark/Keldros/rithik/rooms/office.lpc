#include "../defs.h"
inherit ROOM;
void create(){
  seteuid(getuid());
set("author", "Waxer");
set("light", 1);
set("short", "The Principle's Office");
set("long", @ENDLONG
This is the Principle's office.  A large cedarwood desk dominates this room.
The walls Have four pictures, all of previous principles, and all of them
look cruel.  There is a narrow door to the south.  A small window allows you
to see the forest behind.
ENDLONG );
set("item_desc", ([ "desk" : "This is a principle's desk, the name Thurston
Neidendrower is emblazoned on a name plate.\n",
  "door" : "This looks like a door to a closet.\n",
  "picture" : "These pictures were drawn with fine chalk by a professional.\n",
  "window" : "The window is barred and locked.\n",
]) );
  set("objects", ([ MON(prin) : 1, ]) );
set("exits", ([
    "up" : ROOMS(btower),
    "east" : ROOMS(school),
  "south" : ROOMS(closet),
  ]) );
set("exit_suppress", ({ "up" }) );
::create();
}