// sanjie tianyaodian8.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "偏殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "west": __DIR__"tianyaolang4",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/fengmei": 1 ]) );

  setup();
}
