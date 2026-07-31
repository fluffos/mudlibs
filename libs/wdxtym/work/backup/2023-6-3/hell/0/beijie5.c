// by jjyy

inherit ROOM;

void create()
{
	set("short", "北部荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie4",
		"east" : __DIR__"wulinsan1",
		"west" : __DIR__"wulinsan36",
		"north" : __DIR__"beijie6",
	]));
	set("objects", ([
	]));
	setup();
}