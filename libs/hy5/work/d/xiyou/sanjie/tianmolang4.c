// sanjie tianmolang4.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
	
天魔殿走廊，地上邋遢要死，还有一些不知道是什么的东西
扔在那里。
LONG);

  set("exits", ([
  "east" : __DIR__"tianmolang5",
  "west" : __DIR__"tianmolang3",
]));
  set("outdoors", 0);

  setup();
}
