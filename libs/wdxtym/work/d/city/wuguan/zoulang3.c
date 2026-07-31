//zoulang3.c
inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在长廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。北面就是馆主的卧室了，
东西两面各是东，西厢房。
LONG
	);
	set("no_fight",1);
	set("exits", ([
		"east" : __DIR__"xiangfang1",
		"north" : __DIR__"woshi",
		"south" : __DIR__"zoulang4",
	]));

	setup();
}
