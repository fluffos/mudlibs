// by jjyy

inherit ROOM;

void create()
{
	set("short", "荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinyi12",
		"north" : __DIR__"wulinyi14",
	]));
	//set("objects", ([
	setup();
}
