// sanjie tianyimen1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天一宫门");
  set ("long", @LONG
	
			＃＃＃＃＃
			＃天一宫＃
			＃＃＃＃＃

一坐宏伟的宫殿就在前方，而眼前的这个石牌坊更是高有百
丈，牌坊上写着大大的三个字——〖天一宫〗
LONG);

  set("exits", ([
  "north" : __DIR__"tianyidian1",
  "southdown" : __DIR__"tianyilu3",
]));
  set("outdoors", 1);

  setup();
}
