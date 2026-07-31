// by jjyy

inherit ROOM;

void create()
{
	set("short", "东街三号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"west" : __DIR__"dongjie2",
		"east" : __DIR__"dongjie4",
		"north" : __DIR__"wulinyi5",
		"south" : __DIR__"wulinyi6",
	]));
	set("objects", ([		"/HELL2/GuaiWu5/G/guais" : 10,
	]));
	setup();
}
