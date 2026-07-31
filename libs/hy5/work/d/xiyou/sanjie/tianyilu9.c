// sanjie tianyilu9.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "天一路");
  set ("long", @LONG
	
		天一禁地　没有批准
		
		擅自进入　必遭天谴

一个黑不隆冬的山洞，里面什么都看不见，想进去？好像有
点怕！这里是天一宫禁地，还是走吧。
LONG);

  set("exits", ([ 
  "north" : __DIR__"tianyidong1",
  "southdown" : __DIR__"tianyilu8",
]));
  set("outdoors", 1);

  setup();
}
