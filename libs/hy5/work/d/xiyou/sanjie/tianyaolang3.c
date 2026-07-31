// sanjie tianyaolang3.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
	
天妖殿走廊，地上邋遢要死，还有一些不知道是什么的东西
扔在那里。
LONG);

  set("exits", ([
  "north" : __DIR__"tianyaolang4",
  "west" : __DIR__"tianyaodian5",
  "east" : __DIR__"tianyaodian6",
  "south" : __DIR__"tianyaolang2",
]));
  set("outdoors", 0);

  setup();
}
