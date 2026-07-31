// Room: /u/diabio/feitian/feitian/niurouguan.c
inherit ROOM;

void create()
{
  set ("short", "牛肉馆");
  set ("long", @LONG
你带着满肚子的疑问来到了曾经闻名一时的京都牛肉馆.但这里是一片
废墟,旁边的人告诉你,这里是因为老板娘牵扯到了绯村剑心的战斗
而被摧毁了.
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"beijie",
]));
	set("objects",([
	__DIR__"npc/xiaoyan":1,
]));
  setup();
  replace_program(ROOM);
}
