// sanjie tianyidong3.c

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
  "north" : __DIR__"tianyidong5",
  "southwest" : __DIR__"tianyidong1",
]));
  set("outdoors", 0);

  setup();
}
