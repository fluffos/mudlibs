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
	set("objects", ([		"/HELL2/GuaiWu5/G/guais" : 10,
	]));
	setup();
}