// sanjie tianyaodian2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "雷府前殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "north": __DIR__"tianmodian1",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/leijiang": 1 ]) );

  setup();
}
