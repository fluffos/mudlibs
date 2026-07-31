// sanjie tianyaodian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "偏殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "east": __DIR__"tianyaolang1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/yanjiumei": 1 ]) );

  setup();
}
