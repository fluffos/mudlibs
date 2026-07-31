// sanjie tianyaodian.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "后殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "south": __DIR__"tianyaodian0",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/datianyao": 1 ]) );

  setup();
}
