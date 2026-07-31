//zoulang4.c
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
这是一条长廊，廊顶描绘着江南秀美的风景。每两根翠绿色的柱子间相隔
也就两三尺的距离，朱红色的琉璃瓦，嫩黄色的地砖。在长廊里面，丫鬟、奴
仆们走来走去，都忙着自己的事情，不敢有一点怠慢。往北面走就能到馆主的
卧室了，南面是武馆的大厅。
LONG
	);
	set("no_fight",1);
	set("exits", ([
		"north" : __DIR__"zoulang3",
		"out" : __DIR__"dating",
	]));

	setup();
}
