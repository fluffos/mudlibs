// by jjyy

inherit ROOM;

void create()
{
	set("short", "西街四号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie3",
		"west" : __DIR__"xijie5",
		"north" : __DIR__"wuliner22",
		"south" : __DIR__"wuliner21",
	]));
	set("objects", ([
		"/Aboss1/GW1/G/guais" : 5,
	]));
	setup();
}