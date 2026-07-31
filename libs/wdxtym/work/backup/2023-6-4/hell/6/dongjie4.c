// by jjyy

inherit ROOM;

void create()
{
	set("short", "东街四号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie3",
		"east" : __DIR__"dongjie5",
		"north" : __DIR__"wuliner7",
		"south" : __DIR__"wuliner8",
	]));
	set("objects", ([
		"/HELL6/GuaiWu3/G/guais" : 3,
	]));
	setup();
}
