// sanjie tianyaodian9.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "前殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "north": __DIR__"tianyaodian0",
  "west": __DIR__"tianyaofood",
  "east": __DIR__"tianyaorest",
  "south": __DIR__"tianyaolang4",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/yaoge": 1 ]) );

  setup();
}
