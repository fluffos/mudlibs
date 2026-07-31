// Room: /d/emei/jiudaoguai2.c 峨嵋派 九十九道拐2

inherit ROOM;

void create()
{
	set("short", "九十九道拐");
	set("long", @LONG
你现在已经深入到山谷腹地，只见在正对面的悬崖间有两股山泉，相交
成特大的“人”字，飞流直下，溅珠捣玉。绕着一条窄窄的山梁，有条小路
盘沿而到瀑布上方。石梁上面人工凿出一格格阶梯。边上钉了几棵木桩，绕
上粗长的麻绳作为扶手。
LONG
	);
        set("outdoors", "emei");
	set("exits", ([
		"northeast" : __DIR__"jiudaoguai1",
                "southup": __DIR__"jiudaoguai3",
	]));

	setup();
}



