// sanjie tianyidian2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "偏殿");
  set ("long", @LONG
	
殿上灯火通明，有几个小道士忙着打扫着殿上的清洁卫生，
这里并没有什么人间香火，显得格外宁静。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyilang2",
  "east" : __DIR__"tianyidian1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/huanwangzi": 1 ]) );

  setup();
}
