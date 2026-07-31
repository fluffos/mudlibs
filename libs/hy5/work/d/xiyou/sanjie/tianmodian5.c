// sanjie tianyaodian5.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天魔殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "west": __DIR__"tianmolang5",
  "south": __DIR__"tianmorest",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/datianmo": 1 ]) );

  setup();
}
