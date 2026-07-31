// by jjyy

inherit ROOM;

void create()
{
	set("short", "北空间四号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"beijie3",
		"north" : __DIR__"beijie5",
		"east" : __DIR__"wuliner1",
		"west" : __DIR__"wuliner28",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,
	]));
	setup();
}