// sanjie tianyaodian4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "雷府后殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "south": __DIR__"tianmodian3",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/dianjiang": 1 ]) );

  setup();
}
