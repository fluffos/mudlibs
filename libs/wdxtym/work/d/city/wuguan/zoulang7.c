//zoulang7.c
inherit ROOM;

void create()
{
	set("short", "东廊");
	set("long", @LONG
这是一条走廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在走廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。往东过了回廊就能到后
花园了，北面是男弟子的休息室，而南面是女弟子的休息室。
LONG
	);
	set("no_fight",1);
	set("exits", ([
		"west" : __DIR__"zoulang6",
		"east" : __DIR__"huilang",
		"north" : __DIR__"xxshi1",
		"south" : __DIR__"xxshi2",
	]));

	setup();
}

int valid_leave(object me, string dir)
{
	if ((me->query("gender") =="男性") && dir =="south" )
		return notify_fail("嘿嘿，想偷窥女孩子的卧房？\n");
	if ((me->query("gender") == "女性") && dir == "north")
		return notify_fail("女孩子还是不要到那去的好，否则就不好找婆家了。\n");

	return ::valid_leave(me, dir);
}
