

inherit ROOM;

void create()
{
	set("short", "异空间三号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"east" : __DIR__"wulinsan33",
		"south" : __DIR__"wulinsan31",
	]));
	set("objects", (["/SJSSS5/GW1/G/guais" : 3,"/SJSSS5/GW1/G/guais1" : 5,   ]));
	setup();
}
