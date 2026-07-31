// by jjyy

inherit ROOM;

void create()
{
	set("short", "荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wulinyi13",
		"north" : __DIR__"wulinyi15",
	]));
	//set("objects", ([
	setup();
}
