//zoulang5.c
inherit ROOM;

void create()
{
	set("short", "东廊");
	set("long", @LONG
这是一条走廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在走廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。往西走就是武馆的大厅，
东面是走廊的延伸，北面是一间不小的偏厅。
LONG
	);
	set("no_fight",1);
	set("exits", ([
		"westup" : __DIR__"dating",
		"east" : __DIR__"zoulang6",
		"north" : __DIR__"pianting1",
	]));

	setup();
}
