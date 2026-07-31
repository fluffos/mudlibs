
inherit ROOM;

void create()
{
	set("short", "异空间四号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsi7",
		"south" : __DIR__"wulinsi9",
	]));
	set("objects", (["/SJSSS3/GW1/G/guais" : 3,"/SJSSS3/GW1/G/guais1" : 5,   ]));
	setup();
}
