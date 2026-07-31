

inherit ROOM;

void create()
{
	set("short", "异空间三号");
	set("long", "这是一个空间地带。");
	set("outdoors", "hell");
	set("exits", ([
		"north" : __DIR__"wulinsan7",
		"south" : __DIR__"wulinsan9",
	]));
	set("objects", (["/SJSSS2/GW1/G/guais" : 3,"/SJSSS2/GW1/G/guais1" : 5,   ]));
	setup();
}
