// by jjyy

inherit ROOM;

void create()
{
	set("short", "西空间四号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"xijie3",
		"west" : __DIR__"xijie5",
		"north" : __DIR__"wuliner22",
		"south" : __DIR__"wuliner21",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,
	]));
	setup();
}