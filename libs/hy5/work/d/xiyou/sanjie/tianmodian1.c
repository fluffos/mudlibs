// sanjie tianyaodian1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "雷府前殿");
  set ("long", @LONG
	
一坐妖气冲天的宫殿。
LONG);

  set("exits", ([
  "north": __DIR__"tianmolang1",
  "south": __DIR__"tianmodian2",
]));
  set("outdoors", 0);
  set("objects", ([
                __DIR__"npc/guxianfeng": 1,
                __DIR__"npc/qinxianfeng": 1,
                __DIR__"npc/guixianfeng": 1 ]) );

  setup();
}
