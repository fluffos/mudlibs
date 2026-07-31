
inherit ROOM;

void create()
{
	set("short", "异空间四号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsi20",
		"west" : __DIR__"wulinsi22",
	]));
	set("objects", (["/SJSSS9/GW1/G/guais" : 3,"/SJSSS9/GW1/G/guais1" : 5,   ]));
	setup();
}
