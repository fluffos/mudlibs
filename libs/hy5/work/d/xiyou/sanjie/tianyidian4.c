// sanjie tianyidian4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG
	
殿上灯火通明，有几个小道士忙着打扫着殿上的清洁卫生，
这里并没有什么人间香火，显得格外宁静。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyimen2",
  "west" : __DIR__"tianyilang4",
  "east" : __DIR__"tianyilang5",
  "south" : __DIR__"tianyilang1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/zhaoyang": 1 ]) );

  setup();
}
