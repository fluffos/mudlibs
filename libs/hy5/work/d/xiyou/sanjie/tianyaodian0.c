// sanjie tianyaodian0.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "中殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "north": __DIR__"tianyaodian",
  "south": __DIR__"tianyaodian9",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/yaoshuai": 1 ]) );

  setup();
}
