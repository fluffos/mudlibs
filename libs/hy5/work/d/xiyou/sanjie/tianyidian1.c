// sanjie tianyidian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天一大殿");
  set ("long", @LONG
	
殿上灯火通明，有几个小道士忙着打扫着殿上的清洁卫生，
这里并没有什么人间香火，显得格外宁静。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilang1",
  "west" : __DIR__"tianyidian2",
  "east" : __DIR__"tianyidian3",
  "south" : __DIR__"tianyimen1",
]));
  set("outdoors", 0);

  setup();
}
