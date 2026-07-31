// sanjie tianmolang1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
	
雷府殿走廊，地上邋遢要死，还有一些不知道是什么的东西
扔在那里。
LONG);

  set("exits", ([
  "northwest" : __DIR__"tianmolu6",
  "south" : __DIR__"tianmodian1",
]));
  set("outdoors", 0);

  setup();
}
