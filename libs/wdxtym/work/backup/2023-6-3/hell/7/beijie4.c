// by jjyy

inherit ROOM;

void create()
{
	set("short", "北街四号");
	set("long", "这是一条宽阔的青石街道。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie3",
		"north" : __DIR__"beijie5",
		"east" : __DIR__"wuliner1",
		"west" : __DIR__"wuliner28",
	]));
	set("objects", ([
		"/d/publicnpc/killplayer" : 5,
	]));
	setup();
}