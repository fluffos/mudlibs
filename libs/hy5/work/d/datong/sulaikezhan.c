// Room: /open/dt/sulaikezhan.c

inherit ROOM;

void create()
{
	set("short", "苏来客栈");
	set("long", @LONG
位于南门互近的苏来客栈里住的主要都是南来的关内富商。
这里的房价特别贵，当然服务也是一流的，从这里走出去的人，
从贴身的内衣到身边的姑娘，全部都是崭新的。像这样的客栈在
西北一带还找不出第二家来，所以到大同来做生意的富贾们没有
人不在这里落脚的。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"huayanlu3",
]));

	setup();
	replace_program(ROOM);
}
