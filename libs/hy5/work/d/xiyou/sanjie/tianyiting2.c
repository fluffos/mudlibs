// sanjie tianyiting2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "客厅");
  set ("long", @LONG
	
这里是天一宫门人平常会客的地方，茶香扑鼻，不知道用的
是什么茶叶，决然可以一盏茶就令整个厅房都香催人醉。
LONG);

  set("exits", ([
  "west" : __DIR__"tianyilang1",
  "east" : __DIR__"tianyilang3",
]));
  set("outdoors", 0);

  setup();
}
