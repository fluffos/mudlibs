// Room: /open/dt/hongchanglu1.c

inherit ROOM;

void create()
{
	set("short", "洪昌路");
	set("long", @LONG
洪昌路因东西走向，加之两边都是店铺，挡住了从西北边刮
来的狂风，所以看起来较为洁净，但地面上还是随处可见沙粒滚
动，路上随处可见塞外来的牧民沿街兜售一些小玩意儿，这条路
上没有什么大的店铺，北面是一家货栈。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"hongchanglu2",
  "north" : __DIR__"business",
]));

	set("outdoors","datong");

	set("objects",([
	__DIR__"npc/guard" : 1,
__DIR__"npc/qiaoshou" : 1,]));

	setup();
	replace_program(ROOM);
}
