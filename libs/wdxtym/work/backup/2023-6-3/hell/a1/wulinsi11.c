
inherit ROOM;

void create()
{
	set("short", "异空间四号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsi10",
		"south" : __DIR__"dongjie6",
	]));
	set("objects", (["/SJSSS1/GW1/G/guais" : 5,"/SJSSS1/GW1/G/guais1" : 5,   ]));
	setup();
}
