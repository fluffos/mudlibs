// Room: /open/dt/hongchanglu4.c

inherit ROOM;

void create()
{
	set("short", "洪昌路");
	set("long", @LONG
洪昌路因东西走向，加之两边都是店铺，挡住了从西北边刮
来的狂风，所以看起来较为洁净，但地面上还是随处可见沙粒滚
动，路上随处可见塞外来的牧民沿街兜售一些小玩意儿，这条路
上没有什么大的店铺，北面是间面馆，南面是大同武馆，西面不
远处就是十字路口了。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"shizilukou",
  "east" : __DIR__"hongchanglu5",
  "south" : __DIR__"wuguan",
  "north" : __DIR__"mianguan",
]));

	set("outdoors","datong");

	setup();
	replace_program(ROOM);
}
