// sanjie tianyidong1.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "禁地");
  set ("long", @LONG
	
一个黑不隆冬的山洞，什么都看不见，阴森恐怖，还是壮胆
往前走走看有什么玄机。
LONG);

  set("exits", ([ 
  "northwest" : __DIR__"tianyidong2",
  "northeast" : __DIR__"tianyidong3",
  "south" : __DIR__"tianyilu9",
]));
  set("outdoors", 0);

  setup();
}
