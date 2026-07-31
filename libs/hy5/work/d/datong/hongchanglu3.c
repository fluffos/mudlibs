// Room: /open/dt/hongchanglu3.c

inherit ROOM;

void create()
{
	set("short", "洪昌路");
	set("long", @LONG
洪昌路因东西走向，加之两边都是店铺，挡住了从西北边刮
来的狂风，所以看起来较为洁净，但地面上还是随处可见沙粒滚
动，路上随处可见塞外来的牧民沿街兜售一些小玩意儿，这条路
上没有什么大的店铺，北面是悦来客栈，南面是一间杂货铺，东
面不远就是十字路口了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"hongchanglu2",
  "east" : __DIR__"shizilukou",
  "south" : __DIR__"zahuopu",
  "north" : __DIR__"ylinn",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
