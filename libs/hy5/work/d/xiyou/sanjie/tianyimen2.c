// sanjie tianyimen2.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "后门");
  set ("long", @LONG
	
后面是宏伟的〖天一宫〗，前面就是天一宫禁地，如果没有
师傅的批准，任何人都不能从这里通过。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilu4",
  "south" : __DIR__"tianyidian4",
]));
  set("outdoors", 1);
  setup();
}
