

inherit ROOM;

void create()
{
	set("short", "异空间三号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan36",
		"west" : __DIR__"wulinsan34",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,   ]));
	setup();
}

