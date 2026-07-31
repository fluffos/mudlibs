// sanjie tianmolu2.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG
	
妖气冲天，路上不时还看见有人骨兽骨，骷髅骨堆也有几座，
天妖宫就在山上，被妖气包围着，不甚心寒。幸好还有天一
宫镇压着妖气，不然这个世界肯定大乱。
LONG);

  set("exits", ([
  "northeast" : __DIR__"tianmolu3",
  "southwest" : __DIR__"tianmolu1",
]));
  set("outdoors", 1);

  setup();
}
