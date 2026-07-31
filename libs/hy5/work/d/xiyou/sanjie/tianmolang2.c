// sanjie tianmolang2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
	
电府殿走廊，地上邋遢要死，还有一些不知道是什么的东西
扔在那里。
LONG);

  set("exits", ([
  "north" : __DIR__"tianmodian3",
  "southeast" : __DIR__"tianmolu7",
]));
  set("outdoors", 0);

  setup();
}
