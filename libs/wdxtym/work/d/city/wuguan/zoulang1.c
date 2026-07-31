//zoulang1.c
inherit ROOM;

void create()
{
	set("short", "西廊");
	set("long", @LONG
这是一条走廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在走廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。西面传出阵阵诱人的香
气，往北走就到了后院，南面是一个练武场。
LONG
	);
	set("no_fight",1);
	set("exits", ([
		"west" : __DIR__"chufang",
		"east" : __DIR__"zoulang2",
		"north" : __DIR__"shilu1",
		"south" : __DIR__"wuchang2",
	]));

	setup();
}
