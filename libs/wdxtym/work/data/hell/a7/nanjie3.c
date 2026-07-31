// by jjyy

inherit ROOM;

void create()
{
	set("short", "南空间三号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"nanjie2",
		"south" : __DIR__"nanjie4",
		"east" : __DIR__"wulinyi10",
		"west" : __DIR__"wulinyi11",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,
	]));
	setup();
}