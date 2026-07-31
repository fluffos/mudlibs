// by jjyy

inherit ROOM;

void create()
{
	set("short", "东部荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie1",
		"east" : __DIR__"dongjie3",
	]));
	set("objects", ([
	]));
	setup();
}
