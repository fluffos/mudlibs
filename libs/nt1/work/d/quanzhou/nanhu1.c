// Room: /d/quanzhou/nanhu1.c
// Date: May 21, 96   Jay

inherit ROOM;

void init();
int do_out();

void create()
{
	set("short", "嘉兴南湖");
	set("long", @LONG
这里是烟波浩淼的南湖。湖上几只画舫在游荡，船上的游客和青楼女
子在嘻笑。湖水很深，没有船是渡不过去的。但不知是谁在湖底钉了一些
木桩。桩顶潜在水面之下一两寸的地方。即使是不懂轻功的人走上去也像
是水上漂的样子。
LONG );
	set("exits", ([
		"south"     : __DIR__"yanyu",
                "northwest" : __DIR__ "nanhu",
	]));
	set("outdoors", "quanzhou");
	setup();
}

