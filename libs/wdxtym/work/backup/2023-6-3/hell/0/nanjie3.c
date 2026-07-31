// by jjyy

inherit ROOM;

void create()
{
	set("short", "南部荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie2",
		"south" : __DIR__"nanjie4",
		"east" : __DIR__"wulinyi10",
		"west" : __DIR__"wulinyi11",
	]));
	set("objects", ([
	]));
	setup();
}