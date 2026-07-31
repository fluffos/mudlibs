

inherit ROOM;

void create()
{
	set("short", "异空间二号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"south" : __DIR__"wuliner22",
		"north" : __DIR__"wuliner24",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,   ]));
	setup();
}
