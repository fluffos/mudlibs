// by jjyy

inherit ROOM;

void create()
{
	set("short", "东部荒原");
	set("long", "这是一片荒无人烟的地方。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie3",
		"east" : __DIR__"dongjie5",
		"north" : __DIR__"wuliner7",
		"south" : __DIR__"wuliner8",
	]));
	set("objects", ([
	]));
	setup();
}
