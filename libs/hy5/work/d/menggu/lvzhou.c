// Room: /d/menggu/lvzhou
inherit ROOM;

void create()
{
  set ("short", "绿洲");
  set ("long", @LONG
一块沙漠中的绿洲，虽然只有很小的一块，但对于沙漠中的旅行者
而言却已足够。你终于可以停下来歇歇脚了。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"damo2",
  "north" : __DIR__"damo",
]));
  set("outdoors", "menggu");
  setup();
  replace_program(ROOM);
}
