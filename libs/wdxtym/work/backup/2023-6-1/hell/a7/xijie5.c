// by jjyy

inherit ROOM;

void create()
{
	set("short", "西空间五号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie4",
		"north" : __DIR__"wulinsan28",
		"south" : __DIR__"wulinsan27",
	]));
	set("objects", (["/SJSSS7/GW1/G/guais" : 3,"/SJSSS7/GW1/G/guais1" : 5,
	]));
	setup();
}