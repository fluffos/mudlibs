//  /d/emei/zoulang3 走廊3
// crate by host dec,15

inherit ROOM;
void create()
{
	set("short", "走廊");
	set("long", @LONG
这里是长廊的尽头。在北面有一间用竹子扎就的屋子，十分的素雅，竹门
虚掩。仔细听来，可以听到里面偶尔传来阵阵嬉笑声，走到近前，还可以不时
的闻到从里面飘出来的浓郁的香气。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zoulang1",
		"north" : __DIR__"chufang",
	]));

	setup();
}


