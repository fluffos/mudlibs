// sanjie tianyilang2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
	
走廊穿梭在莲花池边，云雾就在池中升起，雾中带有莲花香
气，果然是人间仙景。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilang4",
  "east" : __DIR__"tianyiting1",
  "south" : __DIR__"tianyidian2",
]));
  set("outdoors", 1);

  setup();
}
